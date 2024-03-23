#include "stdafx.h"
#include "CtrlrBuildScriptOutputSection.h"

CtrlrBuildScriptOutputSection::CtrlrBuildScriptOutputSection()
{
    outputView = std::make_unique<TextEditor>("Output");
    addAndMakeVisible(*outputView);
    outputView->setFont(Font(14.0f, Font::plain));
    outputView->setJustification(Justification::topLeft);
    outputView->setReadOnly(true);
    outputView->setColour(TextEditor::textColourId, Colours::black);
    outputView->setColour(TextEditor::backgroundColourId, Colours::white);
    outputView->setMultiLine(true);
    outputView->setScrollbarsShown(true);

    clearButton = std::make_unique<TextButton>("");
    addAndMakeVisible(*clearButton);
    clearButton->setButtonText("Clear Output");
    clearButton->addListener(this);

    setSize(240, 300);
}

CtrlrBuildScriptOutputSection::~CtrlrBuildScriptOutputSection() {}

void CtrlrBuildScriptOutputSection::paint(Graphics& g)
{
    const int buttonHeight = getHeight() / 5;
    
    // Space for outputView Title
    g.setColour(Colours::darkgrey);
    g.fillRect(                             0, 0, getWidth(), buttonHeight);
    // Title for outputView
    g.setColour(Colours::white);
    g.setFont(Font(14.0f, Font::bold));
    g.drawText("Output",                    5, 0, getWidth(), buttonHeight, Justification::left, true);
}

void CtrlrBuildScriptOutputSection::paintOverChildren(Graphics& g)
{
    g.setColour(Colours::darkgrey);
    g.drawRect(0, 0, getWidth(), getHeight(), 1.0);
}

void CtrlrBuildScriptOutputSection::resized()
{
    const int buttonHeight = getHeight() / 12;

	outputView->setBounds(0, buttonHeight * 2, getWidth(), getHeight());
    clearButton->setBounds(getWidth() - 100, getHeight() - 40, 85, 35);
}

void CtrlrBuildScriptOutputSection::buttonClicked(Button* button)
{
	if (button == clearButton.get())
	{
		outputView->clear();
	}
}