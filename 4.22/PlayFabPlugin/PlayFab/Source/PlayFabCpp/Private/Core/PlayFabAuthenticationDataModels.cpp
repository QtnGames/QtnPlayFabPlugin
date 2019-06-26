//////////////////////////////////////////////////////
// Copyright (C) Microsoft. 2018. All rights reserved.
//////////////////////////////////////////////////////


// This is automatically generated by PlayFab SDKGenerator. DO NOT modify this manually!

#include "Core/PlayFabAuthenticationDataModels.h"
#include "Core/PlayFabJsonHelpers.h"

using namespace PlayFab;
using namespace PlayFab::AuthenticationModels;

PlayFab::AuthenticationModels::FEntityKey::~FEntityKey()
{

}

void PlayFab::AuthenticationModels::FEntityKey::writeJSON(JsonWriter& writer) const
{
    writer->WriteObjectStart();

    writer->WriteIdentifierPrefix(TEXT("Id")); writer->WriteValue(Id);

    if (Type.IsEmpty() == false) { writer->WriteIdentifierPrefix(TEXT("Type")); writer->WriteValue(Type); }

    writer->WriteObjectEnd();
}

bool PlayFab::AuthenticationModels::FEntityKey::readFromValue(const TSharedPtr<FJsonObject>& obj)
{
    bool HasSucceeded = true;

    const TSharedPtr<FJsonValue> IdValue = obj->TryGetField(TEXT("Id"));
    if (IdValue.IsValid() && !IdValue->IsNull())
    {
        FString TmpValue;
        if (IdValue->TryGetString(TmpValue)) { Id = TmpValue; }
    }

    const TSharedPtr<FJsonValue> TypeValue = obj->TryGetField(TEXT("Type"));
    if (TypeValue.IsValid() && !TypeValue->IsNull())
    {
        FString TmpValue;
        if (TypeValue->TryGetString(TmpValue)) { Type = TmpValue; }
    }

    return HasSucceeded;
}

PlayFab::AuthenticationModels::FEntityLineage::~FEntityLineage()
{

}

void PlayFab::AuthenticationModels::FEntityLineage::writeJSON(JsonWriter& writer) const
{
    writer->WriteObjectStart();

    if (CharacterId.IsEmpty() == false) { writer->WriteIdentifierPrefix(TEXT("CharacterId")); writer->WriteValue(CharacterId); }

    if (GroupId.IsEmpty() == false) { writer->WriteIdentifierPrefix(TEXT("GroupId")); writer->WriteValue(GroupId); }

    if (MasterPlayerAccountId.IsEmpty() == false) { writer->WriteIdentifierPrefix(TEXT("MasterPlayerAccountId")); writer->WriteValue(MasterPlayerAccountId); }

    if (NamespaceId.IsEmpty() == false) { writer->WriteIdentifierPrefix(TEXT("NamespaceId")); writer->WriteValue(NamespaceId); }

    if (TitleId.IsEmpty() == false) { writer->WriteIdentifierPrefix(TEXT("TitleId")); writer->WriteValue(TitleId); }

    if (TitlePlayerAccountId.IsEmpty() == false) { writer->WriteIdentifierPrefix(TEXT("TitlePlayerAccountId")); writer->WriteValue(TitlePlayerAccountId); }

    writer->WriteObjectEnd();
}

bool PlayFab::AuthenticationModels::FEntityLineage::readFromValue(const TSharedPtr<FJsonObject>& obj)
{
    bool HasSucceeded = true;

    const TSharedPtr<FJsonValue> CharacterIdValue = obj->TryGetField(TEXT("CharacterId"));
    if (CharacterIdValue.IsValid() && !CharacterIdValue->IsNull())
    {
        FString TmpValue;
        if (CharacterIdValue->TryGetString(TmpValue)) { CharacterId = TmpValue; }
    }

    const TSharedPtr<FJsonValue> GroupIdValue = obj->TryGetField(TEXT("GroupId"));
    if (GroupIdValue.IsValid() && !GroupIdValue->IsNull())
    {
        FString TmpValue;
        if (GroupIdValue->TryGetString(TmpValue)) { GroupId = TmpValue; }
    }

    const TSharedPtr<FJsonValue> MasterPlayerAccountIdValue = obj->TryGetField(TEXT("MasterPlayerAccountId"));
    if (MasterPlayerAccountIdValue.IsValid() && !MasterPlayerAccountIdValue->IsNull())
    {
        FString TmpValue;
        if (MasterPlayerAccountIdValue->TryGetString(TmpValue)) { MasterPlayerAccountId = TmpValue; }
    }

    const TSharedPtr<FJsonValue> NamespaceIdValue = obj->TryGetField(TEXT("NamespaceId"));
    if (NamespaceIdValue.IsValid() && !NamespaceIdValue->IsNull())
    {
        FString TmpValue;
        if (NamespaceIdValue->TryGetString(TmpValue)) { NamespaceId = TmpValue; }
    }

    const TSharedPtr<FJsonValue> TitleIdValue = obj->TryGetField(TEXT("TitleId"));
    if (TitleIdValue.IsValid() && !TitleIdValue->IsNull())
    {
        FString TmpValue;
        if (TitleIdValue->TryGetString(TmpValue)) { TitleId = TmpValue; }
    }

    const TSharedPtr<FJsonValue> TitlePlayerAccountIdValue = obj->TryGetField(TEXT("TitlePlayerAccountId"));
    if (TitlePlayerAccountIdValue.IsValid() && !TitlePlayerAccountIdValue->IsNull())
    {
        FString TmpValue;
        if (TitlePlayerAccountIdValue->TryGetString(TmpValue)) { TitlePlayerAccountId = TmpValue; }
    }

    return HasSucceeded;
}

PlayFab::AuthenticationModels::FGetEntityTokenRequest::~FGetEntityTokenRequest()
{
    //if (Entity != nullptr) delete Entity;

}

void PlayFab::AuthenticationModels::FGetEntityTokenRequest::writeJSON(JsonWriter& writer) const
{
    writer->WriteObjectStart();

    if (Entity.IsValid()) { writer->WriteIdentifierPrefix(TEXT("Entity")); Entity->writeJSON(writer); }

    writer->WriteObjectEnd();
}

bool PlayFab::AuthenticationModels::FGetEntityTokenRequest::readFromValue(const TSharedPtr<FJsonObject>& obj)
{
    bool HasSucceeded = true;

    const TSharedPtr<FJsonValue> EntityValue = obj->TryGetField(TEXT("Entity"));
    if (EntityValue.IsValid() && !EntityValue->IsNull())
    {
        Entity = MakeShareable(new FEntityKey(EntityValue->AsObject()));
    }

    return HasSucceeded;
}

PlayFab::AuthenticationModels::FGetEntityTokenResponse::~FGetEntityTokenResponse()
{
    //if (Entity != nullptr) delete Entity;

}

void PlayFab::AuthenticationModels::FGetEntityTokenResponse::writeJSON(JsonWriter& writer) const
{
    writer->WriteObjectStart();

    if (Entity.IsValid()) { writer->WriteIdentifierPrefix(TEXT("Entity")); Entity->writeJSON(writer); }

    if (EntityToken.IsEmpty() == false) { writer->WriteIdentifierPrefix(TEXT("EntityToken")); writer->WriteValue(EntityToken); }

    if (TokenExpiration.notNull()) { writer->WriteIdentifierPrefix(TEXT("TokenExpiration")); writeDatetime(TokenExpiration, writer); }

    writer->WriteObjectEnd();
}

bool PlayFab::AuthenticationModels::FGetEntityTokenResponse::readFromValue(const TSharedPtr<FJsonObject>& obj)
{
    bool HasSucceeded = true;

    const TSharedPtr<FJsonValue> EntityValue = obj->TryGetField(TEXT("Entity"));
    if (EntityValue.IsValid() && !EntityValue->IsNull())
    {
        Entity = MakeShareable(new FEntityKey(EntityValue->AsObject()));
    }

    const TSharedPtr<FJsonValue> EntityTokenValue = obj->TryGetField(TEXT("EntityToken"));
    if (EntityTokenValue.IsValid() && !EntityTokenValue->IsNull())
    {
        FString TmpValue;
        if (EntityTokenValue->TryGetString(TmpValue)) { EntityToken = TmpValue; }
    }

    const TSharedPtr<FJsonValue> TokenExpirationValue = obj->TryGetField(TEXT("TokenExpiration"));
    if (TokenExpirationValue.IsValid())
        TokenExpiration = readDatetime(TokenExpirationValue);


    return HasSucceeded;
}

PlayFab::AuthenticationModels::FValidateEntityTokenRequest::~FValidateEntityTokenRequest()
{

}

void PlayFab::AuthenticationModels::FValidateEntityTokenRequest::writeJSON(JsonWriter& writer) const
{
    writer->WriteObjectStart();

    writer->WriteIdentifierPrefix(TEXT("EntityToken")); writer->WriteValue(EntityToken);

    writer->WriteObjectEnd();
}

bool PlayFab::AuthenticationModels::FValidateEntityTokenRequest::readFromValue(const TSharedPtr<FJsonObject>& obj)
{
    bool HasSucceeded = true;

    const TSharedPtr<FJsonValue> EntityTokenValue = obj->TryGetField(TEXT("EntityToken"));
    if (EntityTokenValue.IsValid() && !EntityTokenValue->IsNull())
    {
        FString TmpValue;
        if (EntityTokenValue->TryGetString(TmpValue)) { EntityToken = TmpValue; }
    }

    return HasSucceeded;
}

PlayFab::AuthenticationModels::FValidateEntityTokenResponse::~FValidateEntityTokenResponse()
{
    //if (Entity != nullptr) delete Entity;
    //if (Lineage != nullptr) delete Lineage;

}

void PlayFab::AuthenticationModels::FValidateEntityTokenResponse::writeJSON(JsonWriter& writer) const
{
    writer->WriteObjectStart();

    if (Entity.IsValid()) { writer->WriteIdentifierPrefix(TEXT("Entity")); Entity->writeJSON(writer); }

    if (Lineage.IsValid()) { writer->WriteIdentifierPrefix(TEXT("Lineage")); Lineage->writeJSON(writer); }

    writer->WriteObjectEnd();
}

bool PlayFab::AuthenticationModels::FValidateEntityTokenResponse::readFromValue(const TSharedPtr<FJsonObject>& obj)
{
    bool HasSucceeded = true;

    const TSharedPtr<FJsonValue> EntityValue = obj->TryGetField(TEXT("Entity"));
    if (EntityValue.IsValid() && !EntityValue->IsNull())
    {
        Entity = MakeShareable(new FEntityKey(EntityValue->AsObject()));
    }

    const TSharedPtr<FJsonValue> LineageValue = obj->TryGetField(TEXT("Lineage"));
    if (LineageValue.IsValid() && !LineageValue->IsNull())
    {
        Lineage = MakeShareable(new FEntityLineage(LineageValue->AsObject()));
    }

    return HasSucceeded;
}
