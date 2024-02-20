Инструкция по сборке и запуску программы videoinfo для OS Linux UBUNTU

	1. Установить программу ffmpeg версии 4.2.7

	   sudo apt install ffmpeg=7:4.2.7-0ubuntu0.1

	2. Распаковать архив 

	3. Найти каталог, в который были установлены библиотеки программы
		
		1) Отобразить все каталоги поиска компоновщика ld

			ld --verbose | grep SEARCH_DIR | tr -s ' ;'

		   В моём случае, библиотеки находятся в каталоге /usr/lib/x86_64-linux-gnu

		2) Найти ссылки на разделяемые библиотеки libavcodec.so.* libavformat.so.*
		   В моём случае ссылки имеют имена libavcodec.so.58 и libavformat.so.58

	4. Создать в рабочем каталоге симолические ссылки на libavcodec.so.58 и libavformat.so.58
	
		ln -s /usr/lib/x86_64-linux-gnu/libavcodec.so.58 libavcodec.so
		ln -s /usr/lib/x86_64-linux-gnu/libavformat.so.58 libavformat.so

	5. Запустить makefile или зайти в консоли в рабочий каталог и выполнить команду:

	   g++ main.cpp videoinfo.cpp libavcodec.so libavformat.so -o videonfo -I.

	6. Скопировать в рабочий каталог любой видеофайл

    7. Запустить исполняемый файл videoinfo передав ему качестве аргумента имя видеофайла

	   
	

		
