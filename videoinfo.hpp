#include <string>

#ifndef VIDEO_INFO_HPP
#define VIDEO_INFO_HPP

    using std::string;

    struct AVFormatContext;

    class VideoInfo {

        private:
            
            long duration;      // Продолжительность видеофайла
            long frameNumber;   // Количество кадров в видеофайле
            long streamNumber;  // Количество потоков в видеофайле

            string formatName;      // Имя формата
            string audioCodecName;  // Имя аудиокодека
            string videoCodecName;  // Имя видеокодека

            int audioStreamID; // Идентификатор аудиопотока
            int videoStreamID; // Идентификатор видеопотока

            string errorString; // Строка с ошибкой

            AVFormatContext *p_formatContext; // Указатель на структуру с метаданными видеофайла

        public:

            VideoInfo();
            ~VideoInfo() {}

            long getDuration() const { return duration;     }
            long getFrames()   const { return frameNumber;  }
            int getStreames()  const { return streamNumber; }

            const string & getFormat()     const { return formatName;     }
            const string & getAudioCodec() const { return audioCodecName; }
            const string & getVideoCodec() const { return videoCodecName; }


            const string & getError() const { return errorString; }

            bool getInfo(const char *filename);

            // void showInfo();
            // void showError();

    }; // class VideoInfo

#endif // #VIDEO_INFO_HPP
            
            

            
