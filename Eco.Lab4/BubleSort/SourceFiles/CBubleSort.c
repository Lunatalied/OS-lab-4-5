/*
 * <кодировка символов>
 *   Cyrillic (UTF-8 with signature) - Codepage 65001
 * </кодировка символов>
 *
 * <сводка>
 *   CBubleSort_B4ED74BE
 * </сводка>
 *
 * <описание>
 *   Данный исходный код описывает реализацию интерфейсов CBubleSort_B4ED74BE
 * </описание>
 *
 * <автор>
 *   Copyright (c) 2018 Vladimir Bashev. All rights reserved.
 * </автор>
 *
 */

#include "IEcoSystem1.h"
#include "IEcoInterfaceBus1.h"
#include "IEcoInterfaceBus1MemExt.h"
#include "CBubleSort.h"
#include "IdEcoCalculatorA.h"
#include "IdEcoCalculatorB.h"
#include "IdEcoCalculatorD.h"
#include "IdEcoCalculatorE.h"
#include "CBubleSort.h"
#include "CEcoLab1EnumConnectionPoints.h"
#include "IEcoConnectionPointContainer.h"
#include "IEcoLab1Events.h"

/*
 *
 * <сводка>
 *   Функция QueryInterface
 * </сводка>
 *
 * <описание>
 *   Функция QueryInterface для интерфейса IBubleSort
 * </описание>
 *
 */
int16_t ECOCALLMETHOD CBubleSort_B4ED74BE_QueryInterface(/* in */ struct IBubleSort* me, /* in */ const UGUID* riid, /* out */ void** ppv) {
    CBubleSort_B4ED74BE* pCMe = (CBubleSort_B4ED74BE*)me;
	int16_t result = -1;

    /* Проверка указателей */
    if (me == 0 || ppv == 0) {
        return result;
    }

    /* Проверка и получение запрошенного интерфейса */
    if ( IsEqualUGUID(riid, &IID_IBubleSort) ) {
        *ppv = &pCMe->m_pVTblIBubleSort;
        pCMe->m_pVTblIBubleSort->AddRef((IBubleSort*)pCMe);
    }
    else if ( IsEqualUGUID(riid, &IID_IEcoCalculatorX) ) {
		if (pCMe->m_pInnerUnknown != 0) {
            /* Запрашиваем интерфейс IEcoCalculatorX внутреннего компонента */
            result = pCMe->m_pInnerUnknown->pVTbl->QueryInterface(pCMe->m_pInnerUnknown, riid, ppv);
			return result;
        }
		else {
			*ppv = &pCMe->m_pVTblIX;
			pCMe->m_pVTblIBubleSort->AddRef((IBubleSort*)pCMe);
		}
    }
    else if ( IsEqualUGUID(riid, &IID_IEcoCalculatorY) ) {
        *ppv = &pCMe->m_pVTblIY;
         pCMe->m_pVTblIBubleSort->AddRef((IBubleSort*)pCMe);
    }
	else if ( IsEqualUGUID(riid, &IID_IEcoConnectionPointContainer) ) {
        *ppv = &pCMe->m_pVTblICPC;
        pCMe->m_pVTblIBubleSort->AddRef((IBubleSort*)pCMe);
    }
	else if ( IsEqualUGUID(riid, &IID_IEcoUnknown) ) {
        *ppv = &pCMe->m_pVTblIBubleSort;
         pCMe->m_pVTblIBubleSort->AddRef((IBubleSort*)pCMe);
    }
    else {
        *ppv = 0;
        return -1;
    }

    return 0;
}

/*
 *
 * <сводка>
 *   Функция AddRef
 * </сводка>
 *
 * <описание>
 *   Функция AddRef для интерфейса IBubleSort
 * </описание>
 *
 */
uint32_t ECOCALLMETHOD CBubleSort_B4ED74BE_AddRef(/* in */ struct IBubleSort* me) {
    CBubleSort_B4ED74BE* pCMe = (CBubleSort_B4ED74BE*)me;

    /* Проверка указателя */
    if (me == 0 ) {
        return -1;
    }

    return ++pCMe->m_cRef;
}

/*
 *
 * <сводка>
 *   Функция Release
 * </сводка>
 *
 * <описание>
 *   Функция Release для интерфейса IBubleSort
 * </описание>
 *
 */
uint32_t ECOCALLMETHOD CBubleSort_B4ED74BE_Release(/* in */ struct IBubleSort* me) {
    CBubleSort_B4ED74BE* pCMe = (CBubleSort_B4ED74BE*)me;

    /* Проверка указателя */
    if (me == 0 ) {
        return -1;
    }

    /* Уменьшение счетчика ссылок на компонент */
    --pCMe->m_cRef;

    /* В случае обнуления счетчика, освобождение данных экземпляра */
    if ( pCMe->m_cRef == 0 ) {
        deleteCBubleSort_B4ED74BE((IBubleSort*)pCMe);
        return 0;
    }
    return pCMe->m_cRef;
}

/*
 *
 * <сводка>
 *   Функция Fire_OnSwap
 * </сводка>
 *
 * <описание>
 *   Функция вызова обратного интерфейса
 * </описание>
 *
 */
int16_t ECOCALLMETHOD CBubleSort_B4ED74BE_Fire_OnSwap(/* in */ struct IBubleSort* me, int pos1, int pos2) {
    CBubleSort_B4ED74BE* pCMe = (CBubleSort_B4ED74BE*)me;
    int16_t result = 0;
    uint32_t count = 0;
    uint32_t index = 0;
    IEcoEnumConnections* pEnum = 0;
    IEcoLab1Events* pIEvents = 0;
    EcoConnectionData cd;

    if (me == 0 ) {
        return -1;
    }

    if (pCMe->m_pISinkCP != 0) {
        result = ((IEcoConnectionPoint*)pCMe->m_pISinkCP)->pVTbl->EnumConnections((IEcoConnectionPoint*)pCMe->m_pISinkCP, &pEnum);
        if ( (result == 0) && (pEnum != 0) ) {
            while (pEnum->pVTbl->Next(pEnum, 1, &cd, 0) == 0) {
                result = cd.pUnk->pVTbl->QueryInterface(cd.pUnk, &IID_IEcoLab1Events, (void**)&pIEvents);
                if ( (result == 0) && (pIEvents != 0) ) {
                    result = pIEvents->pVTbl->OnSwap(pIEvents, pos1, pos2);
                    pIEvents->pVTbl->Release(pIEvents);
                }
                cd.pUnk->pVTbl->Release(cd.pUnk);
            }
            pEnum->pVTbl->Release(pEnum);
        }
    }
    return result;
}

/*
 *
 * <сводка>
 *   Функция Fire_OnSwap
 * </сводка>
 *
 * <описание>
 *   Функция вызова обратного интерфейса
 * </описание>
 *
 */
int16_t ECOCALLMETHOD CBubleSort_B4ED74BE_Fire_OnFinish(/* in */ struct IBubleSort* me) {
    CBubleSort_B4ED74BE* pCMe = (CBubleSort_B4ED74BE*)me;
    int16_t result = 0;
    uint32_t count = 0;
    uint32_t index = 0;
    IEcoEnumConnections* pEnum = 0;
    IEcoLab1Events* pIEvents = 0;
    EcoConnectionData cd;

    if (me == 0 ) {
        return -1;
    }

    if (pCMe->m_pISinkCP != 0) {
        result = ((IEcoConnectionPoint*)pCMe->m_pISinkCP)->pVTbl->EnumConnections((IEcoConnectionPoint*)pCMe->m_pISinkCP, &pEnum);
        if ( (result == 0) && (pEnum != 0) ) {
            while (pEnum->pVTbl->Next(pEnum, 1, &cd, 0) == 0) {
                result = cd.pUnk->pVTbl->QueryInterface(cd.pUnk, &IID_IEcoLab1Events, (void**)&pIEvents);
                if ( (result == 0) && (pIEvents != 0) ) {
                    result = pIEvents->pVTbl->OnFinish(pIEvents);
                    pIEvents->pVTbl->Release(pIEvents);
                }
                cd.pUnk->pVTbl->Release(cd.pUnk);
            }
            pEnum->pVTbl->Release(pEnum);
        }
    }
    return result;
}


/*
 *
 * <сводка>
 *   Функция MyFunction
 * </сводка>
 *
 * <описание>
 *   Функция
 * </описание>
 *
 */
void ECOCALLMETHOD CBubleSort_B4ED74BE_MyFunction(/* in */ struct IBubleSort* me, void * first, size_t size, size_t sizeType, int (ECOCDECLMETHOD * comparator ) (const void * , const void * )) {
    CBubleSort_B4ED74BE* pCMe = (CBubleSort_B4ED74BE*)me;
	size_t i = 0, j = 0, k = 0;
	byte* arr = (byte*)first;
	void * temp;
	temp = pCMe->m_pIMem->pVTbl->Alloc(pCMe->m_pIMem, sizeType);
	

	for (i = 0; i < size - 1; ++i) {
		for (j = 0; j < size - 1 - i; ++j){
			if (comparator(arr + j*sizeType, arr + (j + 1)*sizeType)){
				
				pCMe->m_pIMem->pVTbl->Copy(pCMe->m_pIMem, temp, (arr + j*sizeType), sizeType);
				pCMe->m_pIMem->pVTbl->Copy(pCMe->m_pIMem, (arr + j*sizeType), (arr + (j + 1)*sizeType), sizeType);
				pCMe->m_pIMem->pVTbl->Copy(pCMe->m_pIMem, (arr + (j + 1)*sizeType), temp, sizeType);
				CBubleSort_B4ED74BE_Fire_OnSwap(me, j, j+1);
			}
		}
	}

	CBubleSort_B4ED74BE_Fire_OnFinish(me);

	pCMe->m_pIMem->pVTbl->Free(pCMe->m_pIMem, temp);
}



int16_t CBubleSort_B4ED74BE_IEcoCalculatorX_QueryInterface(/* in */ struct IEcoCalculatorX* me, /* in */ const UGUID* riid, /* out */ void** ppv) {
    CBubleSort_B4ED74BE* pCMe = (CBubleSort_B4ED74BE*)((uint64_t)me - sizeof(struct IBubleSort*));
    int16_t result = -1;

    /* Проверка указателей */
    if (me == 0 || ppv == 0) {
        return result;
	}


    /* Проверка и получение запрошенного интерфейса */
    if ( IsEqualUGUID(riid, &IID_IBubleSort) ) {
        *ppv = &pCMe->m_pVTblIBubleSort;
        pCMe->m_pVTblIBubleSort->AddRef((IBubleSort*)pCMe);
    }
    else if ( IsEqualUGUID(riid, &IID_IEcoCalculatorX) ) {
        if (pCMe->m_pInnerUnknown != 0) {
            /* Запрашиваем интерфейс IEcoCalculatorX внутреннего компонента */
            result = pCMe->m_pInnerUnknown->pVTbl->QueryInterface(pCMe->m_pInnerUnknown, riid, ppv);
			return result;
        }
		else {
			*ppv = &pCMe->m_pVTblIX;
			pCMe->m_pVTblIBubleSort->AddRef((IBubleSort*)pCMe);
		}
    }
    else if ( IsEqualUGUID(riid, &IID_IEcoCalculatorY) ) {
        *ppv = &pCMe->m_pVTblIY;
        pCMe->m_pVTblIBubleSort->AddRef((IBubleSort*)pCMe);
    }
	else if ( IsEqualUGUID(riid, &IID_IEcoConnectionPointContainer) ) {
        *ppv = &pCMe->m_pVTblICPC;
        pCMe->m_pVTblIBubleSort->AddRef((IBubleSort*)pCMe);
    }
	else if ( IsEqualUGUID(riid, &IID_IEcoUnknown) ) {
        *ppv = &pCMe->m_pVTblIBubleSort;
        pCMe->m_pVTblIBubleSort->AddRef((IBubleSort*)pCMe);
    }
    else {
        *ppv = 0;
        return -1;
    }

    return 0;
}



/*
 *
 * <сводка>
 *   Функция AddRef
 * </сводка>
 *
 * <описание>
 *   Функция AddRef для интерфейса IEcoCalculatorX
 * </описание>
 *
 */
uint32_t CBubleSort_B4ED74BE_IEcoCalculatorX_AddRef(/* in */ struct IEcoCalculatorX* me) {
    CBubleSort_B4ED74BE* pCMe = (CBubleSort_B4ED74BE*)((uint64_t)me - sizeof(struct IBubleSort*));

    /* Проверка указателя */
    if (me == 0 ) {
        return -1;
    }

    return ++pCMe->m_cRef;
}

/*
 *
 * <сводка>
 *   Функция Release
 * </сводка>
 *
 * <описание>
 *   Функция Release для интерфейса IEcoCalculatorY
 * </описание>
 *
 */
uint32_t CBubleSort_B4ED74BE_IEcoCalculatorX_Release(/* in */ struct IEcoCalculatorX* me) {
    CBubleSort_B4ED74BE* pCMe = (CBubleSort_B4ED74BE*)((uint64_t)me - sizeof(struct IBubleSort*));

    /* Проверка указателя */
    if (me == 0 ) {
        return -1;
    }

    /* Уменьшение счетчика ссылок на компонент */
    --pCMe->m_cRef;

    /* В случае обнуления счетчика, освобождение данных экземпляра */
    if ( pCMe->m_cRef == 0 ) {
        deleteCBubleSort_B4ED74BE((IBubleSort*)pCMe);
        return 0;
    }
    return pCMe->m_cRef;
}


/*
 *
 * <сводка>
 *   Функция Addition
 * </сводка>
 *
 * <описание>
 *   Функция
 * </описание>
 *
 */
int32_t CBubleSort_B4ED74BE_Addition(/* in */ struct IEcoCalculatorX* me, /* in */ int16_t a, /* in */ int16_t b) {
    CBubleSort_B4ED74BE* pCMe = (CBubleSort_B4ED74BE*)((uint64_t)me - sizeof(struct IBubleSort*));
    int32_t result = 0;

    /* Проверка указателей */
    if (me == 0 ) {
        return -1;
    }

    /* Проверка указателя включаемого компонента и вызов метода */
    if (pCMe->m_pIX != 0) {
        result = pCMe->m_pIX->pVTbl->Addition(pCMe->m_pIX, a, b);
    }

    return result;
}


/*
 *
 * <сводка>
 *   Функция Subtraction
 * </сводка>
 *
 * <описание>
 *   Функция
 * </описание>
 *
 */
int16_t CBubleSort_B4ED74BE_Subtraction(/* in */ struct IEcoCalculatorX* me, /* in */ int16_t a, /* in */ int16_t b) {
    CBubleSort_B4ED74BE* pCMe = (CBubleSort_B4ED74BE*)((uint64_t)me - sizeof(struct IBubleSort*));
    int16_t result = 0;

    /* Проверка указателей */
    if (me == 0 ) {
        return -1;
    }

    /* Проверка указателя включаемого компонента и вызов метода */
    if (pCMe->m_pIX != 0) {
        result = pCMe->m_pIX->pVTbl->Subtraction(pCMe->m_pIX, a, b);
    }

    return result;
}


int16_t CBubleSort_B4ED74BE_IEcoCalculatorY_QueryInterface(/* in */ struct IEcoCalculatorY* me, /* in */ const UGUID* riid, /* out */ void** ppv) {
    CBubleSort_B4ED74BE* pCMe = (CBubleSort_B4ED74BE*)((uint64_t)me - sizeof(struct IBubleSort*)*2);
    int16_t result = -1;

    /* Проверка указателей */
    if (me == 0 || ppv == 0) {
        return result;
    }

    /* Проверка и получение запрошенного интерфейса */
    if ( IsEqualUGUID(riid, &IID_IBubleSort) ) {
        *ppv = &pCMe->m_pVTblIBubleSort;
        pCMe->m_pVTblIBubleSort->AddRef((IBubleSort*)pCMe);
    }
    else if ( IsEqualUGUID(riid, &IID_IEcoCalculatorX) ) {
        if (pCMe->m_pInnerUnknown != 0) {
            /* Запрашиваем интерфейс IEcoCalculatorX внутреннего компонента */
            result = pCMe->m_pInnerUnknown->pVTbl->QueryInterface(pCMe->m_pInnerUnknown, riid, ppv);
			return result;
        }
		else {
			*ppv = &pCMe->m_pVTblIX;
			pCMe->m_pVTblIBubleSort->AddRef((IBubleSort*)pCMe);
		}
    }
    else if ( IsEqualUGUID(riid, &IID_IEcoCalculatorY) ) {
        *ppv = &pCMe->m_pVTblIY;
        pCMe->m_pVTblIBubleSort->AddRef((IBubleSort*)pCMe);
    }
	else if ( IsEqualUGUID(riid, &IID_IEcoConnectionPointContainer) ) {
        *ppv = &pCMe->m_pVTblICPC;
        pCMe->m_pVTblIBubleSort->AddRef((IBubleSort*)pCMe);
    }
	else if ( IsEqualUGUID(riid, &IID_IEcoUnknown) ) {
        *ppv = &pCMe->m_pVTblIBubleSort;
        pCMe->m_pVTblIBubleSort->AddRef((IBubleSort*)pCMe);
    }
    else {
        *ppv = 0;
        return -1;
    }

    return 0;
}

/*
 *
 * <сводка>
 *   Функция AddRef
 * </сводка>
 *
 * <описание>
 *   Функция AddRef для интерфейса IEcoCalculatorY
 * </описание>
 *
 */
uint32_t CBubleSort_B4ED74BE_IEcoCalculatorY_AddRef(/* in */ struct IEcoCalculatorY* me) {
    CBubleSort_B4ED74BE* pCMe = (CBubleSort_B4ED74BE*)((uint64_t)me - sizeof(struct IBubleSort*)*2);

    /* Проверка указателя */
    if (me == 0 ) {
        return -1;
    }

    return ++pCMe->m_cRef;
}

/*
 *
 * <сводка>
 *   Функция Release
 * </сводка>
 *
 * <описание>
 *   Функция Release для интерфейса IEcoCalculatorY
 * </описание>
 *
 */
uint32_t CBubleSort_B4ED74BE_IEcoCalculatorY_Release(/* in */ struct IEcoCalculatorY* me) {
    CBubleSort_B4ED74BE* pCMe = (CBubleSort_B4ED74BE*)((uint64_t)me - sizeof(struct IBubleSort*)*2);

    /* Проверка указателя */
    if (me == 0 ) {
        return -1;
    }

    /* Уменьшение счетчика ссылок на компонент */
    --pCMe->m_cRef;

    /* В случае обнуления счетчика, освобождение данных экземпляра */
    if ( pCMe->m_cRef == 0 ) {
        deleteCBubleSort_B4ED74BE((IBubleSort*)pCMe);
        return 0;
    }
    return pCMe->m_cRef;
}


/*
 *
 * <сводка>
 *   Функция Multiplication
 * </сводка>
 *
 * <описание>
 *   Функция
 * </описание>
 *
 */
int32_t CBubleSort_B4ED74BE_Multiplication(/* in */ struct IEcoCalculatorY* me, /* in */ int16_t a, /* in */ int16_t b) {
    CBubleSort_B4ED74BE* pCMe = (CBubleSort_B4ED74BE*)((uint64_t)me - sizeof(struct IBubleSort*)*2);
    int32_t result = 0;

    /* Проверка указателей */
    if (me == 0 ) {
        return -1;
    }

    /* Проверка указателя включаемого компонента и вызов метода */
    if (pCMe->m_pIY != 0) {
        result = pCMe->m_pIY->pVTbl->Multiplication(pCMe->m_pIY, a, b);
    }

    return result;

}


/*
 *
 * <сводка>
 *   Функция Division
 * </сводка>
 *
 * <описание>
 *   Функция
 * </описание>
 *
 */
int16_t CBubleSort_B4ED74BE_Division(/* in */ struct IEcoCalculatorY* me, /* in */ int16_t a, /* in */ int16_t b) {
    CBubleSort_B4ED74BE* pCMe = (CBubleSort_B4ED74BE*)((uint64_t)me - sizeof(struct IEcoCalculatorX*)*2);
    int16_t result = 0;

    /* Проверка указателей */
    if (me == 0 ) {
        return -1;
    }

    /* Проверка указателя включаемого компонента и вызов метода */
    if (pCMe->m_pIY != 0) {
        result = pCMe->m_pIY->pVTbl->Division(pCMe->m_pIY, a, b);
    }

    return result;
}


/*
 *
 * <сводка>
 *   Функция QueryInterface
 * </сводка>
 *
 * <описание>
 *   Функция QueryInterface для интерфейса IEcoConnectionPointContainer
 * </описание>
 *
 */
int16_t ECOCALLMETHOD CBubleSort_B4ED74BE_IEcoConnectionPointContainer_QueryInterface(/* in */ struct IEcoConnectionPointContainer* me, /* in */ const UGUID* riid, /* out */ void** ppv) {
    CBubleSort_B4ED74BE* pCMe = (CBubleSort_B4ED74BE*)((uint64_t)me - sizeof(struct CBubleSort_B4ED74BE*)*3);

    int16_t result = -1;

    /* Проверка указателей */
    if (me == 0 || ppv == 0) {
        return result;
    }

    /* Проверка и получение запрошенного интерфейса */
    if ( IsEqualUGUID(riid, &IID_IBubleSort) ) {
        *ppv = &pCMe->m_pVTblIBubleSort;
        pCMe->m_pVTblIBubleSort->AddRef((IBubleSort*)pCMe);
    }
    else if ( IsEqualUGUID(riid, &IID_IEcoCalculatorX) ) {
		if (pCMe->m_pInnerUnknown != 0) {
            /* Запрашиваем интерфейс IEcoCalculatorX внутреннего компонента */
            result = pCMe->m_pInnerUnknown->pVTbl->QueryInterface(pCMe->m_pInnerUnknown, riid, ppv);
			return result;
        }
		else {
			*ppv = &pCMe->m_pVTblIX;
			pCMe->m_pVTblIBubleSort->AddRef((IBubleSort*)pCMe);
		}
    }
    else if ( IsEqualUGUID(riid, &IID_IEcoCalculatorY) ) {
        *ppv = &pCMe->m_pVTblIY;
         pCMe->m_pVTblIBubleSort->AddRef((IBubleSort*)pCMe);
    }
	else if ( IsEqualUGUID(riid, &IID_IEcoConnectionPointContainer) ) {
        *ppv = &pCMe->m_pVTblICPC;
        pCMe->m_pVTblIBubleSort->AddRef((IBubleSort*)pCMe);
    }
	else if ( IsEqualUGUID(riid, &IID_IEcoUnknown) ) {
        *ppv = &pCMe->m_pVTblIBubleSort;
         pCMe->m_pVTblIBubleSort->AddRef((IBubleSort*)pCMe);
    }
    else {
        *ppv = 0;
        return -1;
    }

    return 0;
}

/*
 *
 * <сводка>
 *   Функция AddRef
 * </сводка>
 *
 * <описание>
 *   Функция AddRef для интерфейса IEcoConnectionPointContainer
 * </описание>
 *
 */
uint32_t ECOCALLMETHOD CBubleSort_B4ED74BE_IEcoConnectionPointContainer_AddRef(/* in */ struct IEcoConnectionPointContainer* me) {
    CBubleSort_B4ED74BE* pCMe = (CBubleSort_B4ED74BE*)((uint64_t)me - sizeof(struct CBubleSort_B4ED74BE*)*3);

    if (me == 0 ) {
        return -1;
    }

    return ++pCMe->m_cRef;
}

/*
 *
 * <сводка>
 *   Функция Release
 * </сводка>
 *
 * <описание>
 *   Функция Release для интерфейса IEcoConnectionPointContainer
 * </описание>
 *
 */
uint32_t ECOCALLMETHOD CBubleSort_B4ED74BE_IEcoConnectionPointContainer_Release(/* in */ struct IEcoConnectionPointContainer* me) {
    CBubleSort_B4ED74BE* pCMe = (CBubleSort_B4ED74BE*)((uint64_t)me - sizeof(struct CBubleSort_B4ED74BE*)*3);

    if (me == 0 ) {
        return -1;
    }

    /* Уменьшение счетчика ссылок на компонент */
    --pCMe->m_cRef;

    /* В случае обнуления счетчика, освобождение данных экземпляра */
    if ( pCMe->m_cRef == 0 ) {
        deleteCBubleSort_B4ED74BE((IBubleSort*)pCMe);
        return 0;
    }
    return pCMe->m_cRef;
}

/*
 *
 * <сводка>
 *   Функция EnumConnectionPoints
 * </сводка>
 *
 * <описание>
 *   Функция
 * </описание>
 *
 */
int16_t ECOCALLMETHOD CBubleSort_B4ED74BE_IEcoConnectionPointContainer_EnumConnectionPoints(/* in */ struct IEcoConnectionPointContainer* me, /* out */ struct IEcoEnumConnectionPoints **ppEnum) {
    CBubleSort_B4ED74BE* pCMe = (CBubleSort_B4ED74BE*)((uint64_t)me - sizeof(struct CBubleSort_B4ED74BE*)*3);
    int16_t result = 0;

    if (me == 0 || ppEnum == 0 ) {
        return -1;
    }

    result = createCEcoLab1EnumConnectionPoints((IEcoUnknown*)pCMe->m_pISys, &pCMe->m_pISinkCP->m_pVTblICP, ppEnum);

    return result;
}

/*
 *
 * <сводка>
 *   Функция FindConnectionPoint
 * </сводка>
 *
 * <описание>
 *   Функция
 * </описание>
 *
 */
int16_t ECOCALLMETHOD CBubleSort_B4ED74BE_IEcoConnectionPointContainer_FindConnectionPoint(/* in */ struct IEcoConnectionPointContainer* me, /* in */ const UGUID* riid, /* out */ struct IEcoConnectionPoint **ppCP) {
    CBubleSort_B4ED74BE* pCMe = (CBubleSort_B4ED74BE*)((uint64_t)me - sizeof(struct CBubleSort_B4ED74BE*)*3);
    int16_t result = 0;

    if (me == 0 || ppCP == 0 ) {
        return -1;
    }

    if ( !IsEqualUGUID(riid, &IID_IEcoLab1Events ) ) {
        *ppCP = 0;
        /* CONNECT_E_NOCONNECTION */
        return -1;
    }

    if (pCMe->m_pISinkCP == 0) {
        /* E_FAIL */
        return -1;
    }

    pCMe->m_pISinkCP->m_pVTblICP->AddRef(&pCMe->m_pISinkCP->m_pVTblICP);
    *ppCP =  &pCMe->m_pISinkCP->m_pVTblICP;

    return 0;
}



/*
 *
 * <сводка>
 *   Функция Init
 * </сводка>
 *
 * <описание>
 *   Функция инициализации экземпляра
 * </описание>
 *
 */
int16_t ECOCALLMETHOD initCBubleSort_B4ED74BE(/*in*/ struct IBubleSort* me, /* in */ struct IEcoUnknown *pIUnkSystem) {
    CBubleSort_B4ED74BE* pCMe = (CBubleSort_B4ED74BE*)me;
    IEcoInterfaceBus1* pIBus = 0;
    int16_t result = -1;
	IEcoUnknown* pOuterUnknown = (IEcoUnknown*)me;

    /* Проверка указателей */
    if (me == 0 ) {
        return result;
    }

    /* Сохранение указателя на системный интерфейс */
    pCMe->m_pISys = (IEcoSystem1*)pIUnkSystem;

	/* Создание точки подключения */
    result = createCEcoLab1ConnectionPoint((IEcoUnknown*)pCMe->m_pISys, &pCMe->m_pVTblICPC, &IID_IEcoLab1Events, (IEcoConnectionPoint**)&((pCMe)->m_pISinkCP));
    if (result == 0 && pCMe->m_pISinkCP != 0) {
        result = 0;
    }

    /* Получение интерфейса для работы с интерфейсной шиной */
    result = pCMe->m_pISys->pVTbl->QueryInterface(pCMe->m_pISys, &IID_IEcoInterfaceBus1, (void **)&pIBus);


	/* Создание внутреннего компонента "B" c поддержкой агрегирования */
    /* ВАЖНО: При агрегировании мы передаем IID IEcoUnknown */
    result = pIBus->pVTbl->QueryComponent(pIBus, &CID_EcoCalculatorB, pOuterUnknown, &IID_IEcoUnknown, (void**) &pCMe->m_pInnerUnknown);
    /* Проверка */
    if (result != 0 || pCMe->m_pIX == 0) {
        /* Получение интерфейса по работе со сложением и вычитанием у компонента "A" */
        result = pIBus->pVTbl->QueryComponent(pIBus, &CID_EcoCalculatorA, 0, &IID_IEcoCalculatorX, (void**) &pCMe->m_pIX);
    }


	/* Получение интерфейса по работе с умножением и делением у компонента "E" c поддержкой агрегирования */
	result = pIBus->pVTbl->QueryComponent(pIBus, &CID_EcoCalculatorE, 0, &IID_IEcoCalculatorY, (void**) &pCMe->m_pIY);
    /* Проверка */
    if (result != 0 || pCMe->m_pIX == 0) {
        /* Получение интерфейса по работе с умножением и делением у компонента "D" */
        result = pIBus->pVTbl->QueryComponent(pIBus, &CID_EcoCalculatorD, 0, &IID_IEcoCalculatorY, (void**) &pCMe->m_pIY);
    }


    /* Освобождение */
    pIBus->pVTbl->Release(pIBus);
	
    return result;
}

/* Create Virtual Table IBubleSort */
IBubleSortVTbl g_x87CE395400A14271A107EB2788B31103VTbl_B4ED74BE = {
    CBubleSort_B4ED74BE_QueryInterface,
    CBubleSort_B4ED74BE_AddRef,
    CBubleSort_B4ED74BE_Release,
    CBubleSort_B4ED74BE_MyFunction
};

IEcoCalculatorXVTbl g_x9322111622484742AE0682819447843DVTblD_B4ED74BE = {
    CBubleSort_B4ED74BE_IEcoCalculatorX_QueryInterface,
    CBubleSort_B4ED74BE_IEcoCalculatorX_AddRef,
    CBubleSort_B4ED74BE_IEcoCalculatorX_Release,
    CBubleSort_B4ED74BE_Addition,
    CBubleSort_B4ED74BE_Subtraction
};

IEcoCalculatorYVTbl g_xBD6414C29096423EA90C04D77AFD1CADVTblD_B4ED74BE = {
    CBubleSort_B4ED74BE_IEcoCalculatorY_QueryInterface,
    CBubleSort_B4ED74BE_IEcoCalculatorY_AddRef,
    CBubleSort_B4ED74BE_IEcoCalculatorY_Release,
    CBubleSort_B4ED74BE_Multiplication,
    CBubleSort_B4ED74BE_Division
};

/* Create Virtual Table IEcoConnectionPointContainer */
IEcoConnectionPointContainerVTbl g_x0000000500000000C000000000000046VTblCPC_B4ED74BE = {
    CBubleSort_B4ED74BE_IEcoConnectionPointContainer_QueryInterface,
    CBubleSort_B4ED74BE_IEcoConnectionPointContainer_AddRef,
    CBubleSort_B4ED74BE_IEcoConnectionPointContainer_Release,
    CBubleSort_B4ED74BE_IEcoConnectionPointContainer_EnumConnectionPoints,
    CBubleSort_B4ED74BE_IEcoConnectionPointContainer_FindConnectionPoint
};


/*
 *
 * <сводка>
 *   Функция Create
 * </сводка>
 *
 * <описание>
 *   Функция создания экземпляра
 * </описание>
 *
 */
int16_t ECOCALLMETHOD createCBubleSort_B4ED74BE(/* in */ IEcoUnknown* pIUnkSystem, /* in */ IEcoUnknown* pIUnkOuter, /* out */ IBubleSort** ppIBubleSort) {
    int16_t result = -1;
    IEcoSystem1* pISys = 0;
    IEcoInterfaceBus1* pIBus = 0;
    IEcoInterfaceBus1MemExt* pIMemExt = 0;
    IEcoMemoryAllocator1* pIMem = 0;
    CBubleSort_B4ED74BE* pCMe = 0;
    UGUID* rcid = (UGUID*)&CID_EcoMemoryManager1;
	
    /* Проверка указателей */
    if (ppIBubleSort == 0 || pIUnkSystem == 0) {
        return result;
    }

    /* Получение системного интерфейса приложения */
    result = pIUnkSystem->pVTbl->QueryInterface(pIUnkSystem, &GID_IEcoSystem1, (void **)&pISys);

    /* Проверка */
    if (result != 0 && pISys == 0) {
        return result;
    }

    /* Получение интерфейса для работы с интерфейсной шиной */
    result = pISys->pVTbl->QueryInterface(pISys, &IID_IEcoInterfaceBus1, (void **)&pIBus);

	/* Получение идентификатора компонента для работы с памятью */
    result = pIBus->pVTbl->QueryInterface(pIBus, &IID_IEcoInterfaceBus1MemExt, (void**)&pIMemExt);
    if (result == 0 && pIMemExt != 0) {
        rcid = (UGUID*)pIMemExt->pVTbl->get_Manager(pIMemExt);
        pIMemExt->pVTbl->Release(pIMemExt);
    }

    /* Получение интерфейса распределителя памяти */
    pIBus->pVTbl->QueryComponent(pIBus, rcid, 0, &IID_IEcoMemoryAllocator1, (void**) &pIMem);

    /* Проверка */
    if (result != 0 && pIMem == 0) {
        /* Освобождение системного интерфейса в случае ошибки */
        pISys->pVTbl->Release(pISys);
        return result;
    }

    /* Выделение памяти для данных экземпляра */
    pCMe = (CBubleSort_B4ED74BE*)pIMem->pVTbl->Alloc(pIMem, sizeof(CBubleSort_B4ED74BE));

    /* Сохранение указателя на системный интерфейс */
    pCMe->m_pISys = pISys;

    /* Сохранение указателя на интерфейс для работы с памятью */
    pCMe->m_pIMem = pIMem;

    /* Установка счетчика ссылок на компонент */
    pCMe->m_cRef = 1;

    /* Создание таблицы функций интерфейса IBubleSort */
    pCMe->m_pVTblIBubleSort = &g_x87CE395400A14271A107EB2788B31103VTbl_B4ED74BE;
	pCMe->m_pVTblIX = &g_x9322111622484742AE0682819447843DVTblD_B4ED74BE;
	pCMe->m_pVTblIY = &g_xBD6414C29096423EA90C04D77AFD1CADVTblD_B4ED74BE;
	pCMe->m_pVTblICPC = &g_x0000000500000000C000000000000046VTblCPC_B4ED74BE;

    /* Инициализация данных */
    pCMe->m_Name = 0;

    /* Возврат указателя на интерфейс */
    *ppIBubleSort = (IBubleSort*)pCMe;

    /* Освобождение */
    pIBus->pVTbl->Release(pIBus);

    return 0;
}

/*
 *
 * <сводка>
 *   Функция Delete
 * </сводка>
 *
 * <описание>
 *   Функция освобождения экземпляра
 * </описание>
 *
 */
void ECOCALLMETHOD deleteCBubleSort_B4ED74BE(/* in */ IBubleSort* pIBubleSort) {
    CBubleSort_B4ED74BE* pCMe = (CBubleSort_B4ED74BE*)pIBubleSort;
    IEcoMemoryAllocator1* pIMem = 0;

    if (pIBubleSort != 0 ) {
        pIMem = pCMe->m_pIMem;
        /* Освобождение */
        if ( pCMe->m_Name != 0 ) {
            pIMem->pVTbl->Free(pIMem, pCMe->m_Name);
        }
        if ( pCMe->m_pISys != 0 ) {
            pCMe->m_pISys->pVTbl->Release(pCMe->m_pISys);
        }
        pIMem->pVTbl->Free(pIMem, pCMe);
        pIMem->pVTbl->Release(pIMem);
    }
}
