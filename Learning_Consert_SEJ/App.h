#pragma once
class App
{
private:
	R_W_Lectures* RW;
public:
	App();
	~App();
private:
	void logo();
	void ending();
public:
	void make_Xlsx();
	void run();
	void init();
	void exit();
};


