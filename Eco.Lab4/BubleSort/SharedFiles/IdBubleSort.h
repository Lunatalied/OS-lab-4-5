/*
 * <кодировка символов>
 *   Cyrillic (UTF-8 with signature) - Codepage 65001
 * </кодировка символов>
 *
 * <сводка>
 *   IdBubleSort
 * </сводка>
 *
 * <описание>
 *   Данный заголовок описывает интерфейс IdBubleSort
 * </описание>
 *
 * <ссылка>
 *
 * </ссылка>
 *
 * <автор>
 *   Copyright (c) 2018 Vladimir Bashev. All rights reserved.
 * </автор>
 *
 */

#ifndef __ID_BUBLESORT_H__
#define __ID_BUBLESORT_H__

#include "IEcoBase1.h"
#include "IBubleSort.h"

/* BubleSort CID = {680786EC-2FB7-42F2-A3C6-C9D4B4ED74BE} */
#ifndef __CID_BubleSort
static const UGUID CID_BubleSort = {0x01, 0x10, 0x68, 0x07, 0x86, 0xEC, 0x2F, 0xB7, 0x42, 0xF2, 0xA3, 0xC6, 0xC9, 0xD4, 0xB4, 0xED, 0x74, 0xBE};
#endif /* __CID_BubleSort */

/* Фабрика компонента для динамической и статической компановки */
#ifdef ECO_DLL
ECO_EXPORT IEcoComponentFactory* ECOCALLMETHOD GetIEcoComponentFactoryPtr();
#elif ECO_LIB
extern IEcoComponentFactory* GetIEcoComponentFactoryPtr_680786EC2FB742F2A3C6C9D4B4ED74BE;
#endif

#endif /* __ID_BUBLESORT_H__ */
