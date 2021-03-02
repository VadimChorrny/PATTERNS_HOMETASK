#pragma once

__interface Device
{
	bool isEnabled();
	void enable();
	void disable();
	const size_t& getVolume()const;
	void setVolume(size_t volume);
	const size_t& getChanel()const;
	void setChanel(size_t channel);

};

class Remote : public Device
{
private:
	bool state;
	Device* device;
public:
	Remote() = default;
	Remote(Device* device,size_t volume,bool state):device(device),state(state){}
	bool isEnabled() override
	{
		return state;
	}
	void togglePower()
	{
		if (isEnabled())
		{
			device->disable();
		}
		else
		{
			device->enable();
		}
	}
	void volumeDown()
	{
		device->setVolume(device->getVolume() - 10);
	}
	void volumeUp()
	{
		device->setVolume(device->getVolume() + 10);
	}
	void channelDown()
	{
		device->setChanel(device->getChanel() - 1);
	}
	void channelUp()
	{
		device->setChanel(device->getChanel() + 1);
	}
};

class AdvancedRemote : public Remote
{
private:
	Device* device;
public:
	void mute()
	{
		device->setVolume(0);
	}
};

class TV : public Device
{

};

class Radio : public Device
{

};

void client()
{
}

// add TV and Radio