#pragma once
#include <DShow.h>

class CDXGraph
{
private:
	IGraphBuilder *m_pGraphBuilder;
	IVideoWindow *m_pVideoWindow;
	IMediaControl *m_pMediaControl;
	IMediaSeeking *m_pMediaSeeking;
	IMediaEventEx *m_pMediaEvent;
	IBasicAudio *m_pBasicAudio;
	IBasicVideo *m_pBasiVideo;
};