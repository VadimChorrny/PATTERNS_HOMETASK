#pragma once
#include <iostream>
using namespace std;

__interface Button
{
	void render();
	void onClick();
};

class WindowsButton : public Button
{
private:
	size_t w_counter;
public:
	void render() override
	{
		cout << "Windows button has been touch " << w_counter << endl;
	}
	void onClick() override
	{
		w_counter++;
		cout << "touch..." << endl;
	}
};

class HTMLButton : public Button
{
private:
	size_t h_counter;
public:
	void render() override
	{
		cout << "HTML button has been touch " << h_counter << endl;
	}
	void onClick() override
	{
		h_counter++;
		cout << "touch..." << endl;
	}
};

class Dialog
{
public:
	void render()
	{
		Button* btn = createButton();
		btn->onClick();
		btn->render();
	}

	virtual Button* createButton() const = 0;
};

class WindowsDialog : public Dialog
{
public:
	Button* createButton() const override
	{
		return new WindowsButton;
	}
};

class HTMLDialog : public Dialog
{
public:
	Button* createButton() const override
	{
		return new HTMLButton;
	}
};

void ClientCode(const Dialog& dialog)
{
	cout << "...." << dialog.createButton() << endl;
}