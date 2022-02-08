#include "animatedsplashscreen.h"

AnimatedSplashScreen::AnimatedSplashScreen(QString gifResource)
{
    m_gifResource = gifResource;
    m_pMovie = new QMovie(gifResource);

    connect(m_pMovie, SIGNAL(frameChanged(int)), this, SLOT(movieFrameChanged(int)));

    m_pMovie->start();
}

AnimatedSplashScreen::~AnimatedSplashScreen()
{
    if (m_pMovie->state() == QMovie::MovieState::Running)
    {
        m_pMovie->stop();
    }

    delete m_pMovie;
}

void AnimatedSplashScreen::movieFrameChanged(int frameNumber)
{
    Q_UNUSED(frameNumber)

    pixmap = m_pMovie->currentPixmap();

    setPixmap(pixmap);
}
