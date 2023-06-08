
#include <iostream>
#include <memory>
using namespace std;


// VGA接口类
class VGA {
public:
    virtual void play() = 0;
};

// 支持VGA接口的投影仪类: 投影仪+VGA接口线
class TV01 : public VGA {
public:
    void play() {
        cout << "The projector is connected to VGA port for video playback." << endl;
    }
};

// 仅支持VGA接口的投影仪的电脑类
class Computer {
public:
    void playVideo(unique_ptr<VGA> &pVGA) {
        pVGA->play();
    }
};


class HDMI {
public:
    virtual void play() = 0;
};

// 仅支持HDMI接口的投影仪: 投影仪+HDMI接口线
class TV02 : public HDMI {
public:
    virtual void play() {
        cout << "Connect the projector via HDMI port for video playback." << endl;
    }
};


// 方法一：换一个支持HDMI接口的电脑，这个叫代码重构
// 方法二：买一个转换头（适配器），能够将VGA信号转成HDMI信号，这个叫添加适配器类


class VGAAdapter : public VGA {
public:
    VGAAdapter(HDMI *p) : pHdmi(p) {}
    void play() {
        pHdmi->play();
    }

private:
    shared_ptr<HDMI> pHdmi;
};




int main() {

    Computer computer;

    unique_ptr<VGA> tv01(new TV01);
    computer.playVideo(tv01);

    unique_ptr<VGA> tv02(new VGAAdapter(new TV02()));
    computer.playVideo(tv02);

    return 0;
}














