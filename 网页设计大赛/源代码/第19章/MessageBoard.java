//--------------------------------------------------------------------------------------------
// - MessageBoard.class
// - ��ʾ��JavaScript��Ķ�̬����
// - 2008.8.15
//--------------------------------------------------------------------------------------------
import java.awt.*;										// ����awt���µ�������
import java.applet.*;									// ����applet����������	
public class  MessageBoard extends Applet				// ����һ��JavaС�����࣬��Applet������
{
	private String strMessage = "����δ������Ϣ";		// ����һ����Ϣ�ַ���
	public void paint(Graphics g) 						// �����ػ淽��
	{
		g.drawString( strMessage , 10, 10 );			// �ػ�ʱ���ı����ڴ�����
	}
	public void set_strMessage( String s )				// ������put����
	{
		strMessage = s;									// �����ⲿ���������
		repaint();										// ǿ��Applet�ػ�
	}
}
