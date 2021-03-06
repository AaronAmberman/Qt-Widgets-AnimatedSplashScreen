#ifndef ANIMATEDSPLASHSCREEN_H
#define ANIMATEDSPLASHSCREEN_H

#include <QSplashScreen>
#include <QString>
#include <QMovie>
#include <QPixmap>

class AnimatedSplashScreen : public QSplashScreen
{
    Q_OBJECT
public:
    AnimatedSplashScreen(QString gifResource);
    ~AnimatedSplashScreen();

private slots:
    void movieFrameChanged(int frameNumber);

private:
    QString m_gifResource = "";
    QMovie *m_pMovie = nullptr;
    QPixmap pixmap;
};

#endif // ANIMATEDSPLASHSCREEN_H
