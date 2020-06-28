//--------------------------------------------------------------------------------------------
// - MessageBoard.class
// - 演示与JavaScript间的动态交互
// - 2008.8.15
//--------------------------------------------------------------------------------------------
import java.awt.*;										// 导入awt包下的所有类
import java.applet.*;									// 导入applet包的所有类	
public class  MessageBoard extends Applet				// 定义一个Java小程序类，从Applet类派生
{
	private String strMessage = "您还未加载消息";		// 定义一个消息字符串
	public void paint(Graphics g) 						// 窗口重绘方法
	{
		g.drawString( strMessage , 10, 10 );			// 重绘时画文本画在窗口上
	}
	public void set_strMessage( String s )				// 变量的put方法
	{
		strMessage = s;									// 保存外部传入的数据
		repaint();										// 强制Applet重绘
	}
}
