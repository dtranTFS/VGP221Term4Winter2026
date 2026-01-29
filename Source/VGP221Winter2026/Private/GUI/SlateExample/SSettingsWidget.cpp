// Fill out your copyright notice in the Description page of Project Settings.


#include "GUI/SlateExample/SSettingsWidget.h"
#include "SlateOptMacros.h"

BEGIN_SLATE_FUNCTION_BUILD_OPTIMIZATION
void SSettingsWidget::Construct(const FArguments& InArgs)
{
	GameHUD = InArgs._GameHUD;
	MyInt = InArgs._MyInt;

	// Vertical Box Settings
	const FMargin ContentPadding(800.0f, 300.0f);

	// Title Settings
	const FText TitleText = FText::FromString("Settings Menu");
	FSlateFontInfo TitleFont = FCoreStyle::Get().GetFontStyle("EmbassedText");
	TitleFont.Size = 60;

	// Button Settings
	const FMargin ButtonPadding(10.0f);
	FSlateFontInfo ButtonFont = FCoreStyle::Get().GetFontStyle("EmbassedText");
	ButtonFont.Size = 40;

	const FText ResumeButtonText = FText::FromString("RESUME");
	const FText IntButtonText = FText::FromString("INT");
	const FText QuitButtonText = FText::FromString("QUIT");
	
	ChildSlot
	[
		SNew(SOverlay)
		+SOverlay::Slot()
		.HAlign(HAlign_Fill)
		.VAlign(VAlign_Fill)
		[
			SNew(SImage)
			.ColorAndOpacity(FLinearColor::Black)
		]
		+SOverlay::Slot()
		.HAlign(HAlign_Fill)
		.VAlign(VAlign_Fill)
		.Padding(ContentPadding)
		[
			SNew(SVerticalBox)
			// Title Text
			+SVerticalBox::Slot()
			[
				SNew(STextBlock)
				.Text(TitleText)
				.Font(TitleFont)
				.Justification(ETextJustify::Center)
			]
			// Resume Button
			+SVerticalBox::Slot()
			.Padding(ButtonPadding)
			[
				SNew(SButton)
				.OnClicked(this, &SSettingsWidget::OnResumeClicked)
				[
					SNew(STextBlock)
					.Text(ResumeButtonText)
					.Font(ButtonFont)
					.Justification(ETextJustify::Center)
				]
			]
			// Int Button
			+ SVerticalBox::Slot()
			.Padding(ButtonPadding)
			[
				SNew(SButton)
				.OnClicked(this, &SSettingsWidget::OnIntClicked)
				[
					SNew(STextBlock)
					.Text(IntButtonText)
					.Font(ButtonFont)
					.Justification(ETextJustify::Center)
				]
			]
			// Quit Button
			+ SVerticalBox::Slot()
			.Padding(ButtonPadding)
			[
				SNew(SButton)
				.OnClicked(this, &SSettingsWidget::OnQuitClicked)
				[
					SNew(STextBlock)
					.Text(QuitButtonText)
					.Font(ButtonFont)
					.Justification(ETextJustify::Center)
				]
			]
		]
	];
}
FReply SSettingsWidget::OnResumeClicked() const
{
	if(GameHUD.IsValid())
	{
		GameHUD->HideSettingsMenu();
	}

	return FReply::Handled();
}
FReply SSettingsWidget::OnIntClicked() const
{
	UE_LOG(LogTemp, Warning, TEXT("MyInt: %i"), MyInt);
	return FReply::Handled();
}
FReply SSettingsWidget::OnQuitClicked() const
{
	if (GameHUD.IsValid())
	{
		if (APlayerController* PC = GameHUD->PlayerOwner) {
			PC->ConsoleCommand("quit");
		}
	}
	return FReply::Handled();
}
END_SLATE_FUNCTION_BUILD_OPTIMIZATION
