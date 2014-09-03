/**
*@file 
*@brief ����Ч��ʵ��
*
*
*
*@author DionysosLai��email: 906391500@qq.com
*@version 1.0
*@data 2014-8-22 15:58
*/

#ifndef __ERASER_SPRITE_H__
#define __ERASER_SPRITE_H__

#include "cocos2d.h"

class EraserSprite : public cocos2d::CCSprite, public cocos2d::CCTargetedTouchDelegate
{
public:
	EraserSprite();
	~EraserSprite();

///@brief ������������
///@param[in] pszFileName--�����ļ���, eraserImmediately---�Ƿ������������ true---���ԣ� false---����
///@param[in] drawType---������״�� 0---�����Σ�1---Բ�Σ� 2---�Զ�����״(����һ��ͼƬ����)
///@pre 
///@return 
	static EraserSprite* create(const char *pszFileName, const bool& eraserImmediately = true, 
		const unsigned int& drawType = 0);

	virtual bool init(const char *pszFileName, const bool& eraserImmediately = true, 
		const unsigned int& drawType = 0);

	virtual void onEnter();
	virtual void onExit();

	virtual bool ccTouchBegan(cocos2d::CCTouch *pTouch, cocos2d::CCEvent *pEvent);
	virtual void ccTouchMoved(cocos2d::CCTouch *pTouch, cocos2d::CCEvent *pEvent);

public:
	CC_PROPERTY(bool, m_bEraser, Eraser);			///< �����Ƿ���Բ���
	CC_PROPERTY(float, m_fDrawWidth, DrawWidth);	///< ������С��Ĭ��Ϊ10.f;
	CC_PROPERTY(bool, m_bEraserOk, EraserOk);		///< �Ƿ�������

///@brief �Զ��������״
///@param[in/out] 
///@pre ͼƬҪ���м���״���οյġ�
///@return 
	void setDrawStencil(const char *pszFileName);	
private:
///@brief ���û��ģʽ��ʵ�ֲ���Ч��
///@param[in/out] 
///@pre ע�⣬�������
///@return 
	void eraseByBlend(cocos2d::CCPoint& point);
	void eraseByColorMask();

private:
	void initData(const char *pszFileName, const bool& eraserImmediately = true, 
		const unsigned int& drawType = 0);

	cocos2d::CCSize spriteSize;				///< �����С
	unsigned int m_uiDrawType;				///< ������״ 0---�����Σ� 1---Բ�� 2--�Զ�����״

	cocos2d::CCPoint m_touchPoint;			///< ������
	cocos2d::CCTexture2D* m_drawTextture;	///< �Զ���ͼƬʱ�����õĲ���ͼƬ
	
	cocos2d::CCRenderTexture* m_pRTex;		///< ��Ⱦ����
	cocos2d::CCDrawNode* m_pEraser;			///< ��Ⱦ�ڵ�
};
	
#endif	///< __ERASER_SPRITE_H__