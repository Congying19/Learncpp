#pragma once
#ifndef TV_H_
#define TV_H_
//友元类：两个类既不是is-a也不是has-a，例如遥控器和电视，遥控器能控制电视，所以应该作为友元类

class Tv
{
public:
	friend class Remote;
	enum {Off,On};//开 关
	enum {MinVal,MaxVal = 20};//音量
	enum {Antenna,Cable};//频道
	enum {TV,DVD};//播放器

	Tv(int s = Off, int mc = 125):state(s),volume(5),maxchannel(mc),
		channel(2),mode(Cable),input(TV){ }
	//如果电视是开的就关上，是关的就开
	void onoff() { state = (state == On) ? Off : On; }
	bool ison() const { return state == On; }
	bool volup();
	bool voldown();
	void chanup();
	void chandown();
	void set_mode() { mode = (mode == Antenna) ? Cable : Antenna; }
	void set_input() { input = (input == TV) ? DVD : TV; }
	void settings()const;
private:
	int state;//状态：on or off
	int volume;//
	int maxchannel;//
	int channel;
	int mode;
	int input;
};
class Remote//遥控器用来调模式
{
private:
	int mode;
public:
	Remote(int m =Tv::TV):mode(m){}//友元类可以直接使用公有部分
	bool volup(Tv& t) { return t.volup(); }//增加音量
	bool voldown(Tv& t) { return t.voldown(); }//降低音量
	void onoff(Tv& t) { t.onoff(); }//开关
	void chanup(Tv& t) { t.chanup(); }//频道加
	void chandown(Tv& t) { t.chandown(); }//频道减
	void set_chan(Tv& t, int c) { t.channel = c; }//直接跳转
	void set_mode(Tv& t) { t.set_mode(); }//设置模式
	void set_input(Tv& t) { t.set_input(); }//TVorDVD
};

#endif