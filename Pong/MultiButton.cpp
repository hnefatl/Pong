#include "MultiButton.h"

MultiButton::MultiButton()
{
	Selected=false;
	DropDown=false;
}
MultiButton::~MultiButton()
{
	for(unsigned int x=0; x<Blips.size(); x++)
	{
		delete Blips[x];
		Blips[x]=NULL;
	}
}

bool MultiButton::HandleEvents(const SDL_Event &Event)
{
	for(unsigned int x=0; x<Blips.size(); x++)
	{
		if(!Blips[x]->HandleEvents(Event))
		{
			return false;
		}
	}
	Button::HandleEvents(Event);
	return true;
}
void MultiButton::Update()
{
	for(unsigned int x=0; x<Blips.size(); x++)
	{
		Blips[x]->Update();
	}
	Button::Update();
}
void MultiButton::Draw(SDL_Renderer *Renderer)
{
	for(unsigned int x=0; x<Blips.size(); x++)
	{
		Blips[x]->Draw(Renderer);
	}
	Button::Draw(Renderer);
}

void MultiButton::AddBlip(Blip *const NewBlip)
{
	NewBlip->SetVisible(false);
	Blips.push_back(NewBlip);

	unsigned int HorizontalSpacing=5;
	unsigned int VerticalSpacing=DropDown?-10:10;

	unsigned int TotalLength=0;
	for(unsigned int x=0; x<Blips.size(); x++)
	{
		TotalLength+=Blips[x]->GetPosition().w+HorizontalSpacing;
	}
	TotalLength-=HorizontalSpacing;

	unsigned int RunningLength=0;
	for(unsigned int x=0; x<Blips.size(); x++)
	{
		Blips[x]->SetPosition((Position.x+(Position.w/2))-(TotalLength/2)+RunningLength, VerticalSpacing);
		HorizontalSpacing+=Blips[x]->GetPosition().w+HorizontalSpacing;
	}
}