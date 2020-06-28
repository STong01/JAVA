package {
	import flash.display.Sprite;			// 导入下面使用到的各个类
	import flash.events.Event;
	import flash.external.ExternalInterface;
	import flash.system.Security;
	import flash.text.TextField;
	import flash.text.TextFormat;
	import flash.text.TextFieldAutoSize;
	public class MessageBoard extends Sprite
	{
		public var msg:TextField;		// 消息文本域引用
		public function MessageBoard()		// SWF对象构造函数
		{
			Security.allowDomain("*");	// 允许所有域访问
			this.loaderInfo.addEventListener(Event.INIT,onInit);	// 添加初始化完毕事件的侦听器
		 	msg = new TextField();					// 创建消息文本域对象
			msg.text = "Ready";					// 显示消息，“ready”
			msg.autoSize=TextFieldAutoSize.LEFT;			// 文本靠左对齐
			msg.x = 30;						// 本域对象在舞台的坐标为（30,30）
			msg.y = 30;
			this.addChild( msg );					// 添加文本域对象到舞台
		}
		public function SetMessage( msgTxt:String )			// 设置消息文本方法
		{
			msg.text = msgTxt;					// 设置消息文本域对象的文本
		}
		public function onInit(event:Event)				// 初始化完毕事件的侦听器
		{
			try							// 开始异常捕获
			{
				if( ExternalInterface.available)		// 如果外部API可用
				{
					ExternalInterface.addCallback("SetMessage",SetMessage);	// 注册回调函数“SetMessage”供外部使用
					ExternalInterface.call( "SwfIsReady", 1 );		// 调用外部JavaScript函数“SwfIsReady”
				}
				else
				{
					msg.text = "警告：SWF外部API被禁用!";	// 如果外部API不可用则显示警告
				}
			}
			catch( e:Error )					// 异常捕获后处理
			{
				msg.text = e.message;				// 仅显示出错消息
			}
		} 
	}
}
