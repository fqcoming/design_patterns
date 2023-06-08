
#include <iostream>
#include <memory>
using namespace std;


// 代理模式：通过代理类，来控制实际对象的访问权限
// 客户 => 助理:proxy代理类 => 老板:委托类


class VideoSite {
public:

    virtual void freeMovie() = 0;    // 免费电源
    virtual void vipMovie() = 0;     // vip电源
    virtual void ticketMovie() = 0;  // 用券观看的电影

};


class FixBugVideoSite : public VideoSite {   // 委托类
public:

    virtual void freeMovie()   { cout << "see freeMovie" << endl; }
    virtual void vipMovie()    { cout << "see vipMovie" << endl; } 
    virtual void ticketMovie() { cout << "see ticketMovie" << endl; }

};


class FreeVideoSiteProxy : public VideoSite {   // 代理类
public:  
    FreeVideoSiteProxy()  { pVideo = new FixBugVideoSite(); }
    ~FreeVideoSiteProxy() { delete pVideo; }

    virtual void freeMovie()   { pVideo->freeMovie(); }
    virtual void vipMovie()    { cout << "you are not vip user." << endl; } 
    virtual void ticketMovie() { cout << "you don't have the movie ticket." << endl; }

private:
    VideoSite *pVideo;
};


class vipVideoSiteProxy : public VideoSite {    // 代理类
public:
    vipVideoSiteProxy()  { pVideo = new FixBugVideoSite(); }
    ~vipVideoSiteProxy() { delete pVideo; }

    virtual void freeMovie()   { pVideo->freeMovie(); }
    virtual void vipMovie()    { pVideo->vipMovie(); } 
    virtual void ticketMovie() { cout << "you don't have the movie ticket." << endl; }

private:
    VideoSite *pVideo;
};

class ticketVideoSiteProxy : public VideoSite {    // 代理类
public:
    ticketVideoSiteProxy()  { pVideo = new FixBugVideoSite(); }
    ~ticketVideoSiteProxy() { delete pVideo; }

    virtual void freeMovie()   { pVideo->freeMovie(); }
    virtual void vipMovie()    { cout << "you are not vip user." << endl; } 
    virtual void ticketMovie() { pVideo->ticketMovie(); }

private:
    VideoSite *pVideo;
};


void watchMovie(unique_ptr<VideoSite> &ptr) {
    ptr->freeMovie();
    ptr->vipMovie();
    ptr->ticketMovie();
}


int main() {

    unique_ptr<VideoSite> p1(new FreeVideoSiteProxy());
    unique_ptr<VideoSite> p2(new vipVideoSiteProxy());
    unique_ptr<VideoSite> p3(new ticketVideoSiteProxy());

    watchMovie(p1);
    watchMovie(p2);
    watchMovie(p3);


    return 0;
}




