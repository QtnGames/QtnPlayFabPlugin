//////////////////////////////////////////////////////
// Copyright (C) Microsoft. 2018. All rights reserved.
//////////////////////////////////////////////////////


#include "PlayFabCppBaseModel.h"
#include "PlayFab.h"

using namespace PlayFab;

//QTN_ENGINE_MOD[kain: 4/30/2020] Template declarations inside DLLs must instantiate all types used by that template in order to be usable outside that DLL...
// Failure to do this will result in debug configs throwing unresolved externals during compile because debug handles inline differently
// https://stackoverflow.com/questions/14138360/c-instantiate-template-class-from-dll
// Most of the types for Boxed were implicitly instantiated through use within this DLL, but some types were not
// and must be explicitly instantiated within this DLL for use within Question's gameside PlayFab implementation
template Boxed<FDateTime>;
template Boxed<int32>;
//...QTN_ENGINE_MOD[kain: 4/30/2020]

FString FPlayFabCppBaseModel::toJSONString() const
{
    FString JsonOutString;
    JsonWriter Json = TJsonWriterFactory<TCHAR, TPrettyJsonPrintPolicy<TCHAR> >::Create(&JsonOutString);
    writeJSON(Json);

    if (Json->Close())
    {
        // write log here
    }

    return JsonOutString;
}

void FJsonKeeper::writeJSON(JsonWriter& writer) const
{
    switch (JsonValue->Type)
    {
    case EJson::None:
    {
        break;
    }
    case EJson::Array:
    {
        writer->WriteArrayStart();
        for (auto Elem : JsonValue->AsArray())
        {
            FJsonKeeper(Elem).writeJSON(writer);
        }
        writer->WriteArrayEnd();
        break;
    }
    case EJson::Boolean:
    {
        writer->WriteValue(JsonValue->AsBool());
        break;
    }
    case EJson::Number:
    {
        writer->WriteValue(JsonValue->AsNumber());
        break;
    }
    case EJson::Object:
    {
        writer->WriteObjectStart();
        for (auto Elem : JsonValue->AsObject()->Values)
        {
            writer->WriteIdentifierPrefix(Elem.Key);
            FJsonKeeper(Elem.Value).writeJSON(writer);
        }
        writer->WriteObjectEnd();
        break;
    }
    case EJson::String:
    {
        writer->WriteValue(JsonValue->AsString());
        break;
    }
    case EJson::Null:
    {
        writer->WriteNull();
        break;
    }
    default:
    {
        break;
    }
    }
}

bool FJsonKeeper::readFromValue(const TSharedPtr<FJsonObject>& obj)
{
    return false;
}

bool FJsonKeeper::readFromValue(const TSharedPtr<FJsonValue>& value)
{
    if (value.IsValid())
    {
        JsonValue = value.ToSharedRef();
    }
    return true;
}

void PlayFab::writeDatetime(FDateTime datetime, JsonWriter& writer)
{
    writer->WriteValue(datetime.ToIso8601());
}

FDateTime PlayFab::readDatetime(const TSharedPtr<FJsonValue>& value)
{
    FDateTime DateTimeOut;
    FString DateString = value->AsString();
    if (!FDateTime::ParseIso8601(*DateString, DateTimeOut))
    {
        UE_LOG(LogPlayFabCpp, Error, TEXT("readDatetime - Unable to import FDateTime from Iso8601 String"));
    }

    return DateTimeOut;
}
