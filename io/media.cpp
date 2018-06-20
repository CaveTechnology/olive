#include "media.h"

extern "C" {
	#include <libavformat/avformat.h>
}

Media::Media() {

}

Media::~Media() {
    for (int i=0;i<video_tracks.size();i++) {
        delete video_tracks.at(i);
    }
    for (int i=0;i<audio_tracks.size();i++) {
        delete audio_tracks.at(i);
    }
    video_tracks.clear();
    audio_tracks.clear();
}

long Media::get_length_in_frames(float frame_rate) {
	return ceil((float) length / (float) AV_TIME_BASE * frame_rate);
}