/*
 * <кодировка символов>
 *   Cyrillic (UTF-8 with signature) - Codepage 65001
 * </кодировка символов>
 *
 * <сводка>
 *   CBubleSort
 * </сводка>
 *
 * <описание>
 *   Данный заголовок описывает реализацию компонента CBubleSort
 * </описание>
 *
 * <автор>
 *   Copyright (c) 2018 Vladimir Bashev. All rights reserved.
 * </автор>
 *
 */

#ifndef __C_BUBLESORT_H__
#define __C_BUBLESORT_H__

#include "IBubleSort.h"
#include "IEcoCalculatorX.h"
#include "IEcoCalculatorY.h"
#include "IEcoSystem1.h"
#include "IdEcoMemoryManager1.h"
#include "IEcoEnumConnections.h"
#include "IEcoConnectionPointContainer.h"
#include "CEcoLab1ConnectionPoint.h"

typedef struct CBubleSort_B4ED74BE {

    /* Таблица функций интерфейса IBubleSort */
    IBubleSortVTbl* m_pVTblIBubleSort;

	/* Таблица функций интерфейса IEcoCalculatorX */
    IEcoCalculatorXVTbl* m_pVTblIX;

    /* Таблица функций интерфейса IEcoCalculatorY */
    IEcoCalculatorYVTbl* m_pVTblIY;

	/* Таблица функций интерфейса IEcoConnectionPointContainer */
    IEcoConnectionPointContainerVTbl* m_pVTblICPC;

    /* Счетчик ссылок */
    uint32_t m_cRef;

    /* Интерфейс для работы с памятью */
    IEcoMemoryAllocator1* m_pIMem;

    /* Системный интерфейс */
    IEcoSystem1* m_pISys;

    /* Данные экземпляра */
    char_t* m_Name;

	/* Точка подключения */
    CEcoLab1ConnectionPoint* m_pISinkCP;

	/* Указатель на интерфейс IEcoCalculatorX включаемого компонента */
    IEcoCalculatorX* m_pIX;

	/* Указатель на интерфейс IEcoCalculatorY включаемого компонента */
    IEcoCalculatorY* m_pIY;

	/* Указатель на IEcoUnknown внутреннего компонента */
    IEcoUnknown* m_pInnerUnknown;

} CBubleSort_B4ED74BE, *CBubleSort_B4ED74BEPtr;

/* Инициализация экземпляра */
int16_t ECOCALLMETHOD initCBubleSort_B4ED74BE(/*in*/ struct IBubleSort* me, /* in */ IEcoUnknown *pIUnkSystem);
/* Создание экземпляра */
int16_t ECOCALLMETHOD createCBubleSort_B4ED74BE(/* in */ IEcoUnknown* pIUnkSystem, /* in */ IEcoUnknown* pIUnkOuter, /* out */ IBubleSort** ppIBubleSort);
/* Удаление */
void ECOCALLMETHOD deleteCBubleSort_B4ED74BE(/* in */ IBubleSort* pIBubleSort);

#endif /* __C_BUBLESORT_H__ */
