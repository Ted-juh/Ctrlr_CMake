#pragma once
#include "CtrlrComponents/CtrlrComponent.h"

class CtrlrGroup;

class CtrlrGroupContentComponent : public GroupComponent
{
	public:
		CtrlrGroupContentComponent(CtrlrGroup &_owner);
		~CtrlrGroupContentComponent();
		void customLookAndFeelChanged(LookAndFeelBase *customLookAndFeel = nullptr);

        JUCE_LEAK_DETECTOR(CtrlrGroupContentComponent)

	private:
		CtrlrGroup &owner;
};

class CtrlrGroup  : public CtrlrComponent, public DragAndDropTarget, public CtrlrGrouppingComponent
{
public:

    CtrlrGroup (CtrlrModulator &owner);
    ~CtrlrGroup();

	enum GradientType
	{
		None,
		Vertical,
		Horizontal,
		Radial
	};

	const Array<Font> getFontList();
	static const GradientType gradientFromString(const String &str);
	static const Justification justificationFromString(const String &str);
	void setComponentValue (const double newValue, const bool sendChangeMessage=false);
	double getComponentValue();
	int getComponentMidiValue();
	double getComponentMaxValue();
	const String getComponentText();
	void setComponentText (const String &componentText);
	void valueTreePropertyChanged (ValueTree &treeWhosePropertyHasChanged, const Identifier &property);
	void valueTreeChildrenChanged (ValueTree &treeWhoseChildHasChanged){}
	void valueTreeParentChanged (ValueTree &treeWhoseParentHasChanged){}
	void valueTreeChildAdded (ValueTree& parentTree, ValueTree& childWhichHasBeenAdded){}
    void valueTreeChildRemoved (ValueTree& parentTree, ValueTree& childWhichHasBeenRemoved, int){}
	void valueTreeChildOrderChanged (ValueTree& parentTreeWhoseChildrenHaveMoved, int, int){}
	void setOwned (CtrlrComponent *componentToOwn, const int subIndexInGroup = 0, const bool shouldOwnThisComponent = true);
	void canvasStateRestored();
	const Array<int> getResourceList();
	void modulatorNameChanged (const String &newName);
	bool isInterestedInDragSource (const SourceDetails &dragSourceDetails);
	void itemDropped (const SourceDetails &dragSourceDetails);
	void itemDragExit (const SourceDetails &dragSourceDetails);
	void itemDragEnter (const SourceDetails &dragSourceDetails);
	bool isOwned(CtrlrComponent *componentToCheck);
	Array <CtrlrComponent*> getOwnedChildren();
	void reloadResources(Array <CtrlrPanelResource*> resourcesThatChanged);
	void setResource();
	void customLookAndFeelChanged(LookAndFeelBase *customLookAndFeel = nullptr);
	static void wrapForLua (lua_State *L);
    //[/UserMethods]

    void paint (Graphics& g);
    void resized();

    juce_UseDebuggingNewOperator

private:

	Array <int> values;
	GradientType outlineGradient, backgroundGradient;
	Colour outlineColour1, outlineColour2, backgroundColour1, backgroundColour2;
	float outlineThickness;
	float outlineAngle;
	int textMargin;
	Image groupBackgroundImage;
	CtrlrGroupContentComponent content;
    Label* label;

    CtrlrGroup (const CtrlrGroup&);
    const CtrlrGroup& operator= (const CtrlrGroup&);
};