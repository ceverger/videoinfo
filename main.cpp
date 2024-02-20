#include <iostream>
#include "videoinfo.hpp"

    int main(int argc, char *argv[])
        {

            VideoInfo info;

            if(!info.getInfo(argv[1]))
                {
                    std::cout << info.getError() << std::endl;
                    return -1;
                }

            std::cout << "duration = "    << info.getDuration()   << std::endl;
            std::cout << "format = "      << info.getFormat()     << std::endl;
            std::cout << "frames = "      << info.getFrames()     << std::endl;
            std::cout << "streams = "     << info.getStreames()   << std::endl; 
            std::cout << "audio codec = " << info.getAudioCodec() << std::endl; 
            std::cout << "video codec = " << info.getVideoCodec() << std::endl;
           
            return 0;

        }
