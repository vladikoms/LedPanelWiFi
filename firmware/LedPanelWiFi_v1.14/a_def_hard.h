// ****************** ПРОФИЛИ УСТРОЙСТВ *******************
//
// ВНИМАНИЕ!!! 
// Рекомендации по выбору ядра для ESP32 и ESP8266 и платы для сборки в настройках Arduino IDE смотри в комментариях в начале основного файла скетча.
//
// --------------------------------------------------------

#define HOST_NAME  F("WiFiPanel")

#define LANG  'RUS'           // Определение языка параметров, передаваемых в приложение управления или Web-интерфейс 'RUS','ENG' или другой, определенный в файле a_def_lang.h
                              // Доступные языки смотри в файле a_def_lang.h; Можете при необходимости там же добавить свой язык

#define A_DEF_DEVC 1          // 1 - Настройки профилей ваших устройств вынесены в отдельный файл "a_def_devc.h"
                              // 0 - Настройки профиля вашего устройства размещены ниже в этом файле
                              // Файл "a_def_devc.h" в комплект не входит, нужно создать, скопировать туда настройки профилей ваших устройств
                              // Пример содержимого файла можно взять из архива public.zip
                              
#define A_DEF_PASS 1          // 1 - Настройки API KEY OpenWeatherMap в отдельном файле a_def_pass.h
                              // 0 - Настройки API KEY OpenWeatherMap определен ниже
                              // Файл a_def_pass.h в комплект не входит, нужно создать, скопировать туда указанные строки
                              // Пример содержимого файла можно взять из архива public.zip

                              // Ключ доступа к информации о погоде с сервиса OpenWeatherMap (зарегистрируйтесь на сервере https://openweathermap.org/api и получите свой ключ!)
#define WEATHER_API_KEY "6a4ba421859c9f4166697758b68d889b"  

#define INITIALIZE_TEXTS 0    // Заполнить память текстов бегущей строки текстом из примеров при первичной загрузке прошивки или при смене значения EEPROM_OK, когда
                              // все настройки сбрасываются в значения по-умолчанию

// Варианты профилей для устройства, выполненного на микроконтроллере ESP8266 (NodeMCU, Wemos d1 mini, ...)

#if defined(ESP8266)
#define DEVICE_VARIANT 0      // Поставьте 0 - если ваше устройство использует только часть из доступных компонентов в схемах с ESP8266 - не полная схема
                              // Поставьте 1 - если ваше устройство ИСПОЛЬЗУЕТ ВСЕ ВОЗМОЖНЫЕ К ПОДКЛЮЧЕНИЮ компоненты (кнопка, DFPlayer, SD-card, TM1637, управление питанием) - полная схема
                              // Для варианта DEVICE_VARIANT == 1 обязательно должен быть отключен отладочный вывод в Serial, поскольку пины контроллера, связанные с
                              // отладочным выводом (D9 и D10 / RX и TX) заняты под подключение компонент кнопки и индикатора TM1637
                              
                              // Обратите внимание - пины подключения для DEVICE_VARIANT == 0 и DEVICE_VARIANT == 1 - отличаются
                              // Выполняйте сборку устройства в соответственно с выбранной схемой
                              //
                              // При необходимости измените настройки подключении в соответсвии с вариантом вашего устройства:
                              //   для DEVICE_VARIANT == 0 --> строки 164-224
                              //   для DEVICE_VARIANT == 1 --> строки 226-288
#endif

// ===================================================================
// Если вы собираете матрицу из ленты светодиодов или ОДНОЙ готовой заводской матрицы 8x8, 16x16 или 8x32 -,
// укажите ниже в параметрах WIDTH, HEIGHT, MATRIX_TYPE, CONNECTION_ANGLE и STRIP_DIRECTION значения,
// описывающие размеры вашей матрицы, её тип (змейка / параллельная) и угол подключения.
//
// В параметры META_MATRIX_WIDTH и META_MATRIX_HEIGHT поставьте 1 (матрица состоит из одного сегмента),
// параметры META_MATRIX_TYPE, META_MATRIX_ANGLE, META_MATRIX_DIRECTION не имеют значения

// Если у вас в наличии несколько заводских матриц 8x8, 16x16 или 8x32 и вы из них собираете одну большую сборную матрицу:
//
// MATRIX_TYPE == 0 или MATRIX_TYPE == 1
// 
//   Для сборной матрицы из сегментов одинакового размера и возможности их одинаковой ориентации (угол подключения и направление из угла)
//   укажите ниже в параметрах WIDTH, HEIGHT, MATRIX_TYPE, CONNECTION_ANGLE и STRIP_DIRECTION значения,
//   описывающие размеры, тип и угол подключения ОДНОГО СЕГМЕНТА вашей заводской матрицы.
//
//   WIDTH                   - ширина одной заводской матрицы - одного сегмента
//   HEIGHT                  - высота одной заводской матрицы - одного сегмента
//   MATRIX_TYPE             - тип соединения диодов в сегменте матрицы: 0 - зигзаг, 1 - параллельная
//   CONNECTION_ANGLE        - угол подключения диодов в сегменте: 0 - левый нижний, 1 - левый верхний, 2 - правый верхний, 3 - правый нижний
//   STRIP_DIRECTION         - направление ленты из угла сегмента: 0 - вправо, 1 - вверх, 2 - влево, 3 - вниз
//   MATRIX_INDEX            - не используется
//
//   META_MATRIX_WIDTH       - количество сегментов (заводских матриц) в ширину сборной матрицы
//   META_MATRIX_HEIGHT      - количество сегментов (заводских матриц) в высоту сборной матрицы
//   META_MATRIX_TYPE        - тип сборной матрицы: 0 - зигзаг, 1 - параллельная
//   META_MATRIX_ANGLE       - угол 1-го сегмента сборной матрицы: 0 - левый нижний, 1 - левый верхний, 2 - правый верхний, 3 - правый нижний
//   META_MATRIX_DIRECTION   - направление следующих сегментов сборной матрицы из угла: 0 - вправо, 1 - вверх, 2 - влево, 3 - вниз
// 
//   Все сегменты (заводские матрицы) из которых собрана ваша сборная матрица должны быть одного размера и ориентированы 
//   одинаково по углу подключения и направлению диодов из угла,как описано в параметрах MATRIX_TYPE, CONNECTION_ANGLE и STRIP_DIRECTION.
//   Сами сегменты (заводские матрицы) подключены по типу параллельного подключения или змейкой, последовательность соединения сегментов - 
//   в соответствии с указанными параметрами META_MATRIX_TYPE, META_MATRIX_ANGLE, META_MATRIX_DIRECTION, которые имеют значения, по смыслу такие же, 
//   как для подключения диодов в одной заводской матрице (MATRIX_TYPE, CONNECTION_ANGLE и STRIP_DIRECTION).
//
// MATRIX_TYPE == 2
//
//   Если ваша сборная матрица состоит из матриц различного размера (смесь разных матриц) или нет возможности сориентировать все
//   элементарные матрицы одинаково ао углу подключения и направлению из угла (ввиду длинных проводов для их соединения иежду собой) вы можете указать 
//   значение MATRIX_TYPE == 2 - использовать для адресации светодиодов на ленте (перевод из координат x,y в индекс светодиода) специальный массив индексов, 
//   загружаемый из файла или определенный в скетче как массив PROGMEM. 
//
//   Настройки параметров матрицы для этого типа подключения (MATRIX_TYPE == 2):
//
//   WIDTH                   - полная ширина сборной матрицы, включая все сегменты
//   HEIGHT                  - полная высота  сборной матрицы, включая все сегменты
//   MATRIX_TYPE             - значение должно быть 2 - используется карта индексов
//   CONNECTION_ANGLE        - не используется
//   STRIP_DIRECTION         - не используется
//   MATRIX_INDEX            - место расположения массива индексов 
//                             0 - в сектче в файле index_map.ino 
//                             1 - в файле карты индексов в файловой системе микроконтроллера 
//   META_MATRIX_WIDTH       - значение должно быть обязательно 1
//   META_MATRIX_HEIGHT      - значение должно быть обязательно 1
//   META_MATRIX_TYPE        - не используется
//   META_MATRIX_ANGLE       - не используется
//   META_MATRIX_DIRECTION   - не используется
//
//   Для создания индексного файла (карта индексов) используется утилита LedMapper, которая находится в папке tools проекта.
//   Имя файла индексов имеет формат "WxH.map" где W - ширина матрицы, H - высота матрицы (для матрицы 35x20 имя файла "35x20.map")
//
//   Для загрузки файла в файловую систему микроконтроллера поместите файл в папку data, находящуюся в папке скетча.
//   В меню "Инструменты" Arduino IDE в настройке распределения памяти устройства выберите вариант:
//     Для микроконтроллеров ESP8266 с 4МБ флэш-памяти рекомендуется вариант "Flash Size: 4MB(FS:2MB OTA:~1019KB)"
//     Для микроконтроллеров ESP32   с 4МБ флэш-памяти рекомендуется вариант "Partition scheme: Default 4MB with spiff(1.2MB APP/1.5MB SPIFFS)"; 
//
//   Загрузка выполняется утилитой "ESP8266 LittleFS Data Upload: для контроллеров на базе ESP8266
//   или утилитой "ESP32 LittleFS Data Upload: для контроллеров на базе ESP32
//   Эти утилиты находятся в папке проекта "tools/LittleFS_Uploader" - нужно установить их в IDE согласно инструкции в файлк readme.txt
//
//   Если при старте микроконтроллер не нейдет файл в файловой системе - для адресации диодов на матрице будут использованы  
//   параметры типа матрицы MATRIX_TYPE == 0 - зигзаг
//
//   При указании параметра MATRIX_INDEX == 0 - PROGMEM массив карты индексов imap размещен в скетче в файле index_map.ino
//   Замените содержимое массива imap> приведенное для примера на массив, сформированный для вашей матрице в утилите LedMapper 
// 

// =================== ESP8266 (NodeMCU, Wemos d1) ===================

/*
 * Wemos d1 mini
 * В менеджере плат выбрано NodeMCU v1.0 (ESP-12E)
 */ 
 
#if defined(ESP8266)

#if (DEVICE_VARIANT == 0)

// Внимание !!!
// Для адресации строки/столбца матрицы используется тип int8_t (-128..127), т.к. нужны отрицательные значения для прокрутки часов и текста бегущей строки, 
// поэтому ширина/высота матрицы не может быть больше 128

#define WIDTH 16                // ширина одного сегмента матрицы для MATRIX_TYPE == 0 или MATRIX_TYPE == 1                                       | для MATRIX_TYPE == 2 ПОЛНАЯ ШИРИНА матрицы
#define HEIGHT 16               // высота одного сегмента матрицы для MATRIX_TYPE == 0 или MATRIX_TYPE == 1                                       | для MATRIX_TYPE == 2 ПОЛНАЯ ВЫСОТА матрицы 
#define MATRIX_TYPE 0           // тип соединения диодов в сегменте матрицы: 0 - зигзаг, 1 - параллельная, 2 - использовать карту индексов
#define MATRIX_INDEX 1          // только для MATRIX_TYPE == 2 - место расположения массива индексов 0 - в сектче, 1 - в файле                    | для MATRIX_TYPE == 0 или 1 - поставьте тут 1
#define CONNECTION_ANGLE 1      // угол подключения диодов в сегменте: 0 - левый нижний, 1 - левый верхний, 2 - правый верхний, 3 - правый нижний | для MATRIX_TYPE == 2 - не используется
#define STRIP_DIRECTION 3       // направление ленты из угла сегмента: 0 - вправо, 1 - вверх, 2 - влево, 3 - вниз                                 | для MATRIX_TYPE == 2 - не используется

#define META_MATRIX_WIDTH 1     // количество сегментов в ширину сборной матрицы                                                                  | для MATRIX_TYPE == 2 - не используется
#define META_MATRIX_HEIGHT 1    // количество сегментов в высоту сборной матрицы                                                                  | для MATRIX_TYPE == 2 - не используется
#define META_MATRIX_TYPE 0      // тип сборной матрицы: 0 - зигзаг, 1 - параллельная                                                              | для MATRIX_TYPE == 2 - не используется
#define META_MATRIX_ANGLE 0     // угол 1-го сегмента сборной матрицы: 0 - левый нижний, 1 - левый верхний, 2 - правый верхний, 3 - правый нижний | для MATRIX_TYPE == 2 - не используется
#define META_MATRIX_DIRECTION 0 // направление следующих сегментов сборной матрицы из угла: 0 - вправо, 1 - вверх, 2 - влево, 3 - вниз            | для MATRIX_TYPE == 2 - не используется

#define COLOR_ORDER       GRB   // Порядок цветов на ленте - RGB,RBG,GRB,GBR,BRG,BGR; Если цвет отображается некорректно - меняйте. Начать можно с RGB
#define LED_CHIP       WS2812B  // CHIP ленты для библиотеки FASTLED - это 3-х проводные чипы с программныь SPI.   // Для чипов с аппаратным CLK потребуется изменить функцию allocateLeds() в utility.ino;
                                //   WS2811, WS2812, WS2812B, WS2813, WS2852, APA104, APA106, SK6812, SK6822,      // Поддерживается до 4-х сегментов вывода на свои аппаратные пины, вывод на которые
                                //   TM1803, TM1804, TM1809, TM1812, TM1829, UCS1903, UCS1903B, UCS1904, UCS2903,  // назначены одинаковым LED_CHIP и COLOR_ORDER, Если ленты или порядок цвета в сегментах разные - требуется изменить функцию allocateLeds() в utility.ino;
                                //   PL9823, GE8822, GS1903, GW6205, LPD1886, SM16703

#define DEVICE_TYPE 1           // Использование матрицы: 0 - свернута в трубу для лампы; 1 - плоская матрица в рамке
#define BUTTON_TYPE 1           // Тип кнопки: 0 - сенсорная (touch button); 1 - обычная кнопка на замыкание при нажатии (или если кнопки нет вообще)
#define USE_BUTTON 1            // 1 - использовать кнопку управления; 0 - не использовать 

// --- !!! Внимание - TM1637 не совместим с SD-картой,т.к. используют одни и те же линии При включенном USE_TM1637==1 SD-карта работать не будет !!! ---
// --- !!! Для совместной работы TM1637 и SD-карты исаользуйте кнофигурацию DEVICE_VARIANT == 1 -- там линии разнесены

#define USE_POWER 0             // 1 - использовать отключение питания матрицы через MOSFET / реле; 0 - не использовать 
#define POWER_ON  HIGH          // Для включения  питания матрицы (через MOSFET/реле) подавать на пин POWER_PIN высокий уровень
#define POWER_OFF LOW           // Для вЫключения питания матрицы (через MOSFET/реле) подавать на пин POWER_PIN низкий уровень

#define USE_TM1637 0            // поставьте 1, если используется дополнительный индикатор TM1637, 0 если индикатора нет
#define USE_WEATHER 1           // 1 - использовать получение информации о текущей погоде; 0 - не использовать 
#define USE_E131 0              // 1 - использовать протокол E1.31 для синхронизации устройств или приема внешнего потока на матрицу с Jinx! или другого аналогичного ПО
#define BIG_FONT 0              // 0 - шрифт 5x8, 1 - шрифт  10x16; 2 - шрифт 8x13

// --- !!! Внимание - SD-карта несовместима с TM1637 ,т.к. используют одни и те же линии. При включенном USE_TM1637==1 SD-карта работать не будет !!! ---
// --- !!! Для совместной работы TM1637 и SD-карты исаользуйте кнофигурацию DEVICE_VARIANT == 1 -- там линии разнесены

#define USE_SD 0                // поставьте 0, если у вас нет SD-card модуля
#define FS_AS_SD 0              // при USE_SD == 1; FS_AS_SD == 0 - эффекты на SD-карте, 1 - эффекты в файловой ситеме МК, самого SD-card модуля нет (режим эмуляции SD-карты для эффектов 'SD-карта')
                                // Для USE_SD == 1 - поведение при проигрывании файла эффекта с SD-карты 
#define WAIT_PLAY_FINISHED 1    // 1 - переключаться на следующий эффект только когда весь файл полностью показан; 
                                // 0 - прерывать показ файла с SD-карты по истечении времени эффекта
#define REPEAT_PLAY 0           // 1 - повторное проигрывание текущего эффекта, если время не вышло; 0 - следующий эффект
// -------

// DFPlayer выпускается разными производителями на разных чипах. 
// Оригинальный плеер построен на микросхеме с обозначением на корпусе AS20HH5883-74
// Существует множество клонов DFPlayer от других производителей, построенных на других чипах, например MH2024K-24SS, MH2024K-16SS и др.
// Эти чипы отличаются от оригинальных несколько измененной системой команд. Библиотеке нужно знать команды в каком формате отправлять плееру.
// Укажите ниже какой чип использован в в вашем DFPlayer
// -------
#define USE_MP3 0               // поставьте 0, если у вас нет звуковой карты MP3 плеера
#define DFPLAYER_TYPE 0         // 0 - AS20HH5883-74 (оригинальный); 1 - MH2024K-24SS, MH2024K-16SS (клон)
#define GUARD_DELAY 75          // Задержка между отправкой последовательных команд в модуль DFPlayer
                                // Рекомендуется подбирать опытным путем. Слишком большая задержка может давать суммарно до 0.5 сек замирания эффектов при начале/окончании воспроизведения звука.
                                // Слишком маленькая задержка может приводить к необнаружению плеера прошивкой или даже циклическую перезагрузку контроллера
                                // Если плеер обнаруживается прошивкой, но не удается получить список файлов с SD-карты и в приложении отсутствует выбор звуков
                                // будильника - увеличивайте значение задержки
                                //
                                // Чудеса в решете:
                                //
                                // В некоторых сборках при попытках сохранить настройки будильника или проиграть выбранный в программе в настройках звука файл                                 
                                // Вызывает крах системы с перезагрузкой микроконтроллера. Крах происходит в файле библиотеки плеера DFMiniMp3.h в строке примерно 533 (в версии библиотеки 1.1.1)
                                // в функции sendPacket()
                                // в этой строке --> _serial.write(reinterpret_cast<uint8_t*>(&packet), sizeof(packet));
                                //
                                // Ошибку удалось победить добавив в начало файла DFMiniMp3.h строку 28 следующий дефайн:
                                // #define DfMiniMp3Debug Serial
                                // После компиляции сборки с этой строкой вызов вункций плеера начинает "гадить" в монитор потта, но преер крашиться перестает
                                // Впрочем, если просто закомментировать эту строку и снова пересобрать программу, плеер все равно продолжает работать без "падений".
                                // Необъяснимо, но факт.
// -------

#define LED_PIN D2              // D2 физческий пин ленты
#define PIN_BTN D4              // D4 физическая кнопка подключена сюда (D4 --- КНОПКА --- GND) 
                                // D6 сенсорная кнопка подключена сюда  (D6 - КНОПКА - VCC 3.3V, GND) - при поодключении сенсорной кнопки на D4 контроллер не стартует
#define POWER_PIN D1            // D1 управляющий пин вкл/выкл матрицы через MOSFET / реле; POWER_ON - HIGH, POWER_OFF - LOW
#define SD_CS_PIN D8            // !!! не менять !!! -пин выбора SD карты - ChipSelect; Также SD карта использует D5 (CLK), D6 (MISO), D7 (MOSI) - совместная работа с TM1637 невозможна, т.к. используют те же пины - либо то, либо то
#define STX D3                  // подключен в RX пин (2) модуля DFPlayer
#define SRX D4                  // подключен в TX пин (3) модуля DFPlayer
#define DIO D5                  // D5 TM1637 display DIO pin - требуется для компиляции скетча (USE_TM1637 == 1) - совместная работа с SD-картой невозможна, т.к. используют те же пины - либо то, либо то
#define CLK D7                  // D7 TM1637 display CLK pin - требуется для компиляции скетча (USE_TM1637 == 1) - совместная работа с SD-картой невозможна, т.к. используют те же пины - либо то, либо то

#define DEBUG_SERIAL 1          // включить/выключить отладочный вывод в Serial: 0 - выключено 1 - включено
#endif

#if (DEVICE_VARIANT == 1)
// Схему соединений смотри в папке "schemes" проекта
// ESP8266+ALL.JPG             - подключены все возможные компоненты, сенсорная кнопка (BUTTON_TYPE == 0)
#define WIDTH 16                // ширина одного сегмента матрицы для MATRIX_TYPE == 0 или MATRIX_TYPE == 1                                       | для MATRIX_TYPE == 2 ПОЛНАЯ ШИРИНА матрицы
#define HEIGHT 16               // высота одного сегмента матрицы для MATRIX_TYPE == 0 или MATRIX_TYPE == 1                                       | для MATRIX_TYPE == 2 ПОЛНАЯ ВЫСОТА матрицы 
#define MATRIX_TYPE 0           // тип соединения диодов в сегменте матрицы: 0 - зигзаг, 1 - параллельная, 2 - использовать карту индексов
#define MATRIX_INDEX 1          // только для MATRIX_TYPE == 2 место расположения массива индексов 0 - в сектче, 1 - в файле                      | для MATRIX_TYPE == 0 или 1 - поставьте тут 1
#define CONNECTION_ANGLE 0      // угол подключения диодов в сегменте: 0 - левый нижний, 1 - левый верхний, 2 - правый верхний, 3 - правый нижний | для MATRIX_TYPE == 2 - не используется
#define STRIP_DIRECTION 0       // направление ленты из угла сегмента: 0 - вправо, 1 - вверх, 2 - влево, 3 - вниз                                 | для MATRIX_TYPE == 2 - не используется

#define META_MATRIX_WIDTH 1     // количество сегментов в ширину сборной матрицы                                                                  | для MATRIX_TYPE == 2 - не используется
#define META_MATRIX_HEIGHT 1    // количество сегментов в высоту сборной матрицы                                                                  | для MATRIX_TYPE == 2 - не используется
#define META_MATRIX_TYPE 0      // тип сборной матрицы: 0 - зигзаг, 1 - параллельная                                                              | для MATRIX_TYPE == 2 - не используется
#define META_MATRIX_ANGLE 0     // угол 1-го сегмента сборной матрицы: 0 - левый нижний, 1 - левый верхний, 2 - правый верхний, 3 - правый нижний | для MATRIX_TYPE == 2 - не используется
#define META_MATRIX_DIRECTION 0 // направление следующих сегментов сборной матрицы из угла: 0 - вправо, 1 - вверх, 2 - влево, 3 - вниз            | для MATRIX_TYPE == 2 - не используется

#define COLOR_ORDER        GRB  // Порядок цветов на ленте - RGB,RBG,GRB,GBR,BRG,BGR; Если цвет отображается некорректно - меняйте. Начать можно с RGB
#define LED_CHIP       WS2812B  // CHIP ленты для библиотеки FASTLED - это 3-х проводные чипы с программныь SPI.   // Для чипов с аппаратным CLK потребуется изменить функцию allocateLeds() в utility.ino;
                                //   WS2811, WS2812, WS2812B, WS2813, WS2852, APA104, APA106, SK6812, SK6822,      // Поддерживается до 4-х сегментов вывода на свои аппаратные пины, вывод на которые
                                //   TM1803, TM1804, TM1809, TM1812, TM1829, UCS1903, UCS1903B, UCS1904, UCS2903,  // назначены одинаковым LED_CHIP и COLOR_ORDER, Если ленты или порядок цвета в сегментах разные - требуется изменить функцию allocateLeds() в utility.ino;
                                //   PL9823, GE8822, GS1903, GW6205, LPD1886, SM16703

#define DEVICE_TYPE 1           // Использование матрицы: 0 - свернута в трубу для лампы; 1 - плоская матрица в рамке
#define BUTTON_TYPE 1           // Тип кнопки: 0 - сенсорная (touch button); 1 - обычная кнопка на замыкание при нажатии (или если кнопки нет вообще)
#define USE_BUTTON 1            // 1 - использовать кнопку управления; 0 - не использовать 

#define USE_POWER 0             // 1 - использовать отключение питания матрицы через MOSFET / реле; 0 - не использовать 
#define POWER_ON  HIGH          // Для включения  питания матрицы (через MOSFET/реле) подавать на пин POWER_PIN высокий уровень
#define POWER_OFF LOW           // Для вЫключения питания матрицы (через MOSFET/реле) подавать на пин POWER_PIN низкий уровень

#define USE_TM1637 1            // поставьте 1, если используется дополнительный индикатор TM1637, 0 если индикатора нет
#define USE_WEATHER 1           // 1 - использовать получение информации о текущей погоде; 0 - не использовать 
#define USE_E131 0              // 1 - использовать протокол E1.31 для синхронизации устройств или приема внешнего потока на матрицу с Jinx! или другого аналогичного ПО
#define BIG_FONT 0              // 0 - шрифт 5x8, 1 - шрифт  10x16; 2 - шрифт 8x13

// -------
#define USE_SD 1                // поставьте 0, если у вас нет SD-card модуля
#define FS_AS_SD 0              // при USE_SD == 1; FS_AS_SD == 0 - эффекты на SD-карте, 1 - эффекты в файловой ситеме МК, самого SD-card модуля нет (режим эмуляции SD-карты для эффектов 'SD-карта')
                                // Для USE_SD == 1 - поведение при проигрывании файла эффекта с SD-карты 
#define WAIT_PLAY_FINISHED 1    // 1 - переключаться на следующий эффект только когда весь файл полностью показан; 
                                // 0 - прерывать показ файла с SD-карты по истечении времени эффекта
#define REPEAT_PLAY 0           // 1 - повторное проигрывание текущего эффекта, если время не вышло; 0 - следующий эффект
// -------

// DFPlayer выпускается разными производителями на разных чипах. 
// Оригинальный плеер построен на микросхеме с обозначением на корпусе AS20HH5883-74
// Существует множество клонов DFPlayer от других производителей, построенных на других чипах, например MH2024K-24SS, MH2024K-16SS и др.
// Эти чипы отличаются от оригинальных несколько измененной системой команд. Библиотеке нужно знать команды в каком формате отправлять плееру.
// Укажите ниже какой чип использован в в вашем DFPlayer

// -------
#define USE_MP3 1               // поставьте 0, если у вас нет звуковой карты MP3 плеера
#define DFPLAYER_TYPE 0         // 0 - AS20HH5883-74 (оригинальный); 1 - MH2024K-24SS, MH2024K-16SS (клон)
#define GUARD_DELAY 75          // Задержка между отправкой последовательных команд в модуль DFPlayer
                                // Рекомендуется подбирать опытным путем. Слишком большая задержка может давать суммарно до 0.5 сек замирания эффектов при начале/окончании воспроизведения звука.
                                // Слишком маленькая задержка может приводить к необнаружению плеера прошивкой или даже циклическую перезагрузку контроллера
                                // Если плеер обнаруживается прошивкой, но не удается получить список файлов с SD-карты и в приложении отсутствует выбор звуков
                                // будильника - увеличивайте значение задержки
// -------
                                
// Внимание!!!
// Данная компоновка работает только при отключенном отладочном выводе (DEBUG_SERIAL == 0), поскольку вывод в Serial использует D9 и D10 
// которые в данной схеме заняты под пин кнопки и пин CLK TM1637
// Если используется сенсорная кнопка - для прошивки ESP8266 необходимо отсоединить управляющий провод идущий от кнопки до Rx.
#define DEBUG_SERIAL 0          // включить/выключить отладочный вывод в Serial: 0 - выключено 1 - включено

#define LED_PIN D2              // D2 физческий пин ленты
#define PIN_BTN D9              // кнопка подключена сюда (D9 --- КНОПКА --- GND) 
#define POWER_PIN D1            // управляющий пин вкл/выкл матрицы через MOSFET / реле; POWER_ON - HIGH, POWER_OFF - LOW
#define SD_CS_PIN D8            // !!! не менять !!! - пин выбора SD карты - ChipSelect; Также SD карта использует D5 (CLK), D6 (MISO), D7 (MOSI)
#define STX D3                  // подключен в RX пин (2) модуля DFPlayer
#define SRX D4                  // подключен в TX пин (3) модуля DFPlayer
#define DIO D0                  // TM1637 display DIO pin
#define CLK D10                 // TM1637 display CLK pin

#endif

#endif

// ============================== ESP32 ==============================

/*
 * ESP32
 * В менеджере плат выбрано "ESP32 Dev Module"
 */ 

// Схемы соединений смотри в папке "schemes" проекта
// ESP32+ALL.JPG             - подключены все возможные компоненты, сенсорная кнопка (BUTTON_TYPE == 0)
// ESP32+button_noRELAY.jpg  - нет реле для управления питанием матрицы, обычная кнопка (BUTTON_TYPE == 1)
// ESP32+MOSFET.JPG          - управления питанием матрицы через MOSFET, сенсорная кнопка  (BUTTON_TYPE == 0)

#if defined(ESP32)
#define WIDTH 16                // ширина одного сегмента матрицы для MATRIX_TYPE == 0 или MATRIX_TYPE == 1                                       | для MATRIX_TYPE == 2 ПОЛНАЯ ШИРИНА матрицы
#define HEIGHT 16               // высота одного сегмента матрицы для MATRIX_TYPE == 0 или MATRIX_TYPE == 1                                       | для MATRIX_TYPE == 2 ПОЛНАЯ ВЫСОТА матрицы 
#define MATRIX_TYPE 0           // тип соединения диодов в сегменте матрицы: 0 - зигзаг, 1 - параллельная, 2 - использовать карту индексов
#define MATRIX_INDEX 1          // только для MATRIX_TYPE == 2 место расположения массива индексов 0 - в сектче, 1 - в файле                      | для MATRIX_TYPE == 0 или 1 - поставьте тут 1
#define CONNECTION_ANGLE 1      // угол подключения диодов в сегменте: 0 - левый нижний, 1 - левый верхний, 2 - правый верхний, 3 - правый нижний | для MATRIX_TYPE == 2 - не используется
#define STRIP_DIRECTION 3       // направление ленты из угла сегмента: 0 - вправо, 1 - вверх, 2 - влево, 3 - вниз                                 | для MATRIX_TYPE == 2 - не используется

#define META_MATRIX_WIDTH 1     // количество сегментов в ширину сборной матрицы                                                                  | для MATRIX_TYPE == 2 - не используется
#define META_MATRIX_HEIGHT 1    // количество сегментов в высоту сборной матрицы                                                                  | для MATRIX_TYPE == 2 - не используется
#define META_MATRIX_TYPE 0      // тип сборной матрицы: 0 - зигзаг, 1 - параллельная                                                              | для MATRIX_TYPE == 2 - не используется
#define META_MATRIX_ANGLE 0     // угол 1-го сегмента сборной матрицы: 0 - левый нижний, 1 - левый верхний, 2 - правый верхний, 3 - правый нижний | для MATRIX_TYPE == 2 - не используется
#define META_MATRIX_DIRECTION 0 // направление следующих сегментов сборной матрицы из угла: 0 - вправо, 1 - вверх, 2 - влево, 3 - вниз            | для MATRIX_TYPE == 2 - не используется

#define COLOR_ORDER        GRB  // Порядок цветов на ленте - RGB,RBG,GRB,GBR,BRG,BGR; Если цвет отображается некорректно - меняйте. Начать можно с RGB
#define LED_CHIP       WS2812B  // CHIP ленты для библиотеки FASTLED - это 3-х проводные чипы с программныь SPI.   // Для чипов с аппаратным CLK потребуется изменить функцию allocateLeds() в utility.ino;
                                //   WS2811, WS2812, WS2812B, WS2813, WS2852, APA104, APA106, SK6812, SK6822,      // Поддерживается до 4-х сегментов вывода на свои аппаратные пины, вывод на которые
                                //   TM1803, TM1804, TM1809, TM1812, TM1829, UCS1903, UCS1903B, UCS1904, UCS2903,  // назначены одинаковым LED_CHIP и COLOR_ORDER, Если ленты или порядок цвета в сегментах разные - требуется изменить функцию allocateLeds() в utility.ino;
                                //   PL9823, GE8822, GS1903, GW6205, LPD1886, SM16703

#define DEVICE_TYPE 1           // Использование матрицы: 0 - свернута в трубу для лампы; 1 - плоская матрица в рамке
#define BUTTON_TYPE 1           // Тип кнопки: 0 - сенсорная (touch button); 1 - обычная кнопка на замыкание при нажатии (или если кнопки нет вообще)
#define USE_BUTTON 1            // 1 - использовать кнопку управления; 0 - не использовать 

#define USE_POWER 0             // 1 - использовать отключение питания матрицы через MOSFET / реле; 0 - не использовать 
#define POWER_ON  HIGH          // Для включения  питания матрицы (через MOSFET/реле) подавать на пин POWER_PIN высокий уровень
#define POWER_OFF LOW           // Для вЫключения питания матрицы (через MOSFET/реле) подавать на пин POWER_PIN низкий уровень

#define USE_TM1637 0            // поставьте 1, если используется дополнительный индикатор TM1637, 0 если индикатора нет
#define USE_WEATHER 1           // 1 - использовать получение информации о текущей погоде; 0 - не использовать 
#define USE_E131 0              // 1 - использовать протокол E1.31 для синхронизации устройств или приема внешнего потока на матрицу с Jinx! или другого аналогичного ПО
#define BIG_FONT 0              // 0 - шрифт 5x8, 1 - шрифт  10x16; 2 - шрифт 8x13

// -------
#define USE_SD 1                // поставьте 0, если у вас нет SD-card модуля
#define FS_AS_SD 0              // при USE_SD == 1; FS_AS_SD == 0 - эффекты на SD-карте, 1 - эффекты в файловой ситеме МК, самого SD-card модуля нет (режим эмуляции SD-карты для эффектов 'SD-карта')
                                // Для USE_SD == 1 - поведение при проигрывании файла эффекта с SD-карты 
#define WAIT_PLAY_FINISHED 1    // 1 - переключаться на следующий эффект только когда весь файл полностью показан; 
                                // 0 - прерывать показ файла с SD-карты по истечении времени эффекта
#define REPEAT_PLAY 0           // 1 - повторное проигрывание текущего эффекта, если время не вышло; 0 - следующий эффект
// -------

// DFPlayer выпускается разными производителями на разных чипах. 
// Оригинальный плеер построен на микросхеме с обозначением на корпусе AS20HH5883-74
// Существует множество клонов DFPlayer от других производителей, построенных на других чипах, например MH2024K-24SS, MH2024K-16SS, GB3200B и др.
// Эти чипы отличаются от оригинальных несколько измененной системой команд. Библиотеке нужно знать команды в каком формате отправлять плееру.
// Укажите ниже какой чип использован в в вашем DFPlayer
// -------
#define USE_MP3 0               // поставьте 0, если у вас нет звуковой карты MP3 плеера
#define DFPLAYER_TYPE 0         // 0 - AS20HH5883-74 (оригинальный); 1 - MH2024K-24SS, MH2024K-16SS, GB3200B (клон)
#define GUARD_DELAY 75          // Задержка между отправкой последовательных команд в модуль DFPlayer
                                // Рекомендуется подбирать опытным путем. Слишком большая задержка может давать суммарно до 0.5 сек замирания эффектов при начале/окончании воспроизведения звука.
                                // Слишком маленькая задержка может приводить к необнаружению плеера прошивкой или даже циклическую перезагрузку контроллера
                                // Если плеер обнаруживается прошивкой, но не удается получить список файлов с SD-карты и в приложении отсутствует выбор звуков
                                // будильника - увеличивайте значение задержки
// -------
// Схема подключения для ESP32 - в папке Schemes, файл 'ESP32+ALL.JPG'
 
#define LED_PIN (13U)           // пин ленты
#define PIN_BTN (15U)           // кнопка подключена сюда (PIN --- КНОПКА --- GND)
#define POWER_PIN (26U)         // G26 управляющий пин вкл/выкл матрицы через MOSFET или реле
#define SD_CS_PIN (5U)          // !!!-не менять-!!! -- G5 пин выбора (ChipSelect) SD карты. SD карта использует G5(CS), G18(CLK), G19(MISO), G23(MOSI)  // на SD-shild: D8(CS), D5(CLK), D6(MISO), D7(MOSI)

#define SRX (16U)               // !!!-не менять-!!! -- G16 'RX2' пин ESP32, подключен в TX пин (3) модуля DFPlayer - используется аппаратный Serial2 - Только RX2/TX2 - GPIO 16/17
#define STX (17U)               // !!!-не менять-!!! -- G17 'TX2' пин ESP32, подключен в RX пин (2) модуля DFPlayer - используется аппаратный Serial2 - Только RX2/TX2 - GPIO 16/17

#define DIO (33U)               // TM1637 display DIO pin (так на схеме, но предпочтительнее специалтзированная шина I2С - G21(SDA/DIO))
#define CLK (32U)               // TM1637 display CLK pin (так на схеме, но предпочтительнее специалтзированная шина I2С - G22(SCL/CLK))

#define DEBUG_SERIAL 1          // включить/выключить отладочный вывод в Serial: 0 - выключено 1 - включено
#endif

// =======================================================

#if (A_DEF_DEVC == 1)
#include "a_def_devc.h"         // Если здесь ошибка - смотри комментарий к определению A_DEF_DEVC выше в начале этого файла (строка 49)
#endif

#include "a_def_lang.h"         // Определение языка интерфейса для параметров, передаваемых в приложение управления или WEB-интерфейс

// =======================================================

// ************** ИСПОЛЬЗУЕМЫЕ БИБЛИОТЕКИ ****************

#include "core_version.h"

#if defined(ESP8266)
  #include <ESP8266WiFi.h>
  #include <ESPAsyncTCP.h>       // Библиотека поддержки для AsyncWebServer  -- https://github.com/me-no-dev/ESPAsyncTCP
  #include <ESP8266mDNS.h>
#endif

#if defined(ESP32)
  #include <AsyncTCP.h>          // Библиотека поддержки для AsyncWebServer  -- https://github.com/me-no-dev/AsyncTCP
  #include <ESPmDNS.h>
#endif

#include <ESPAsyncWebServer.h>   // Библиотека асинхронного Web-сервера
#include <ArduinoOTA.h>          // Библиотека обновления "по воздуху"
#include <WiFiUdp.h>             // Библиотека поддержки WiFi
#include <TimeLib.h>             // Библиотека поддержки функций времени
#include <time.h>
#include <EEPROM.h>              // Библиотека поддержки постоянной памяти
#include <ArduinoJson.h>         // Библиотека для работы с JSON (погода, состояние системы)
#include <FastLED.h>             // Установите в менеджере библиотек стандартную библиотеку FastLED

#if (USE_TM1637 == 1)
#include "TM1637Display.h"       // Внимание!!! Библиотека в папке проекта libraries изменена - константы букв и цифр переименованы с вида _1, _A на _1_, _A_ из-за ошибок компиляции для ESP32
#endif 

#include "timerMinim.h"          // Библиотека таймеров
#include "fonts.h"               // Шрифты, определенные для бегущей строки

#if (USE_BUTTON == 1)
#include "GyverButton.h"         // Библиотека поддержки кнопок
#endif

#if (USE_MP3 == 1)
#if defined(ESP32)
#include <HardwareSerial.h>
#else
#include "SoftwareSerial.h"
#endif
#include "DFMiniMp3.h"           // Установите в библиотеку DFMiniMp3 от Makuha по следующей ссылке: ("DFPlayer Mini MP3 by Makuna" https://github.com/Makuna/DFMiniMp3)
#endif                           // Внимание - НЕ ИЗ МЕНЕДЖЕРА БИБЛИОТЕК. В менеджере в настоящее время версия 1.07, по ссылке 1.10. Скетч использует функции, которых нет в 1.07

#if (USE_SD == 1 && FS_AS_SD == 0)
#include <SPI.h>                 // Библиотеки поддержки работы с SD-картой (если НЕ используется режим эмуляции FS as SD)
#include <SD.h>
#endif

#if (USE_E131 == 1)              // Внимание!!! Библиотека в папке проекта libraries изменена - исправлены ошибки, добавлен деструктор, добавлены функции multicast-отправки пакета
#include <ESPAsyncE131.h>        // Библиотека приема потока по протоколу E1.31; Требует установленной библиотеки ESPAcyncUDP
#endif

#include "FS.h"                  // Работа с внутренней файловой системой чипа ESP8266/ESP32
#include <LittleFS.h>            // Формат файловой системы - LittleFS

// =======================================================

#if (A_DEF_PASS == 1)
#include "a_def_pass.h"          // Если здесь ошибка - смотри комментарий к определению A_DEF_PASS выше в начале этого файла (строка 54)
#endif

// =======================================================

#define DEBUGLN(x)   if (vDEBUG_SERIAL) Serial.println(x)
#define DEBUG(x)     if (vDEBUG_SERIAL) Serial.print(x)
#define DEBUGR(x, r) if (vDEBUG_SERIAL) Serial.print(x, r)
