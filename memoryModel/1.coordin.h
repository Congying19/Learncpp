#pragma once
//ͷ�ļ�������һ�����ݣ�
//����ԭ��
//ʹ��#define����const����ķ��ų���
//�ṹ����
//������
//ģ������
//��������
//���ͣ������������������Ӷ���ʹ��ʱ���ᵼ�¶������������⡣��const���ݺ�����������������������ԣ���˿��԰�����ͷ�ļ���


#ifndef COORDIN_H_ //#ifndef��Ϊif not defined ��ʾֻ������ǰû��ʹ��Ԥ����������ָ��#define��������COORDIN_H_ʱ���Ŵ���#ifndef��#endef֮��Ĵ���
//�ܹ�����ͬ�ļ�����ΰ���
#define COORDIN_H_//ͨ��COORDIN_H_���滹Ҫ������ֵ ������ֻ����Ϊ�Ǻ�ʹ�� #define COORDIN_H_;���Ѿ�����������COORDIN_H_��
//��������һ����������COORDIN_H_ʱ������ƻ�û�б����� �ͻ�ִ��#ifndef��#endef֮��Ĵ��� �Ӷ�COORDIN_H_�ͱ������� �´ξͲ�ִ��
//�ṹ����
struct polar
{
	double distance;
	double angle;
};

struct rect
{
	double x;
	double y;
};
//��������
polar rect_to_polar(rect xypos);
void show_polar(polar dapos);
#endif
