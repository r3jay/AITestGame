// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "Blueprint/UserWidget.h"
#include "Components/Button.h"
#include "Components/TextBlock.h"
#include "ButtonWText.generated.h"

/**
 *
 */
DECLARE_DYNAMIC_MULTICAST_DELEGATE(FOnButtonClick);

UCLASS()
class A_RICARDORODZ_API UButtonWText : public UUserWidget
{
	GENERATED_BODY()

public:
	UPROPERTY(BlueprintAssignable, Category = Delegate)
		FOnButtonClick OnButtonClick;

	UPROPERTY(BlueprintReadWrite, EditAnywhere, Category = Text, meta = (InstanceEditable = true))
		FText Info;

	UPROPERTY(BlueprintReadOnly, meta = (BindWidget))
		UButton* ButtonBackground;

	UPROPERTY(BlueprintReadOnly, meta = (BindWidget))
		UTextBlock* Information;


protected:

	virtual void NativePreConstruct() override;

	virtual void NativeConstruct() override;

	UFUNCTION()
		void HandleClick();
};
