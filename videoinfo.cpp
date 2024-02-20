#include <iostream>
#include "videoinfo.hpp"

    extern "C" 
        {
            #include "libavcodec/avcodec.h"
            #include "libavformat/avformat.h"
        }

    VideoInfo::VideoInfo()
        {
            duration = 0;
            frameNumber = 0;
            streamNumber = 0;

            audioStreamID = -1;
            videoStreamID = -1;

            p_formatContext = avformat_alloc_context();           
        }

    bool VideoInfo::getInfo(const char *filename)
        {
            if(p_formatContext == nullptr)
                {
                    errorString = "Could not allocation memory for AVFormatContex!";
                    return false;
                }

            if(filename == nullptr) 
                {
                    errorString = "No input file!";
                    return false;
                }

            
            if(avformat_open_input(&p_formatContext, filename, nullptr, nullptr) < 0) 
                {
                    errorString = "Could not open input file!";
                    return false;
                }            

            duration = p_formatContext->duration;
            formatName = p_formatContext->iformat->long_name;

            if(avformat_find_stream_info(p_formatContext, nullptr) < 0) 
                {
                    errorString = "Could not find stream information!";
                    return false;
                }

            streamNumber = p_formatContext->nb_streams;

            for(unsigned int i = 0; i < p_formatContext->nb_streams; ++i)
                {
                    if(videoStreamID < 0) 
                        {
                            if(p_formatContext->streams[i]->codecpar->codec_type == AVMEDIA_TYPE_VIDEO)
                                {
                                    videoStreamID = i;
                                }
                        }

                    if(audioStreamID < 0)
                        { 
                            if(p_formatContext->streams[i]->codecpar->codec_type == AVMEDIA_TYPE_AUDIO)
                                {
                                    audioStreamID = i;
                                }
                        }
                }

            if(videoStreamID < 0 || audioStreamID < 0) 
                {
                    errorString =  "Could not find video or audio stream ID!";
                    return false;
                }

            frameNumber = p_formatContext->streams[videoStreamID]->nb_frames;

            audioCodecName = avcodec_get_name(p_formatContext->streams[audioStreamID]->codecpar->codec_id);
            videoCodecName = avcodec_get_name(p_formatContext->streams[videoStreamID]->codecpar->codec_id);

            return true;
        }
