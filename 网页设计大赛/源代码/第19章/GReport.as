package {
	import flash.display.Sprite;
	import flash.events.Event;
	import flash.external.ExternalInterface;
	import flash.system.Security;
	import flash.text.TextField;
	
	public class GReport extends Sprite		// 类GReport
	{
		public var m_data:Array;			// 外部传入的顶点数据
		public var m_ptMsgs:Array;			// 坐标信息数组
		public var xArray:Array;			// 分析后的x轴数组
		public var yArray:Array;			// 分析后的y轴数组
		public function GReport()			// 构造函数
		{
			Security.allowDomain("*");		// 允许所有域访问
			this.loaderInfo.addEventListener( Event.INIT, onInit );			// 添加”初始化完成“事件侦听器
			this.addEventListener(Event.ENTER_FRAME,this.onEnterFrame);		// 添加”每一帧“事件侦听器
			this.m_data = new Array();		// 创建外部传入的顶点数据数组
			this.m_ptMsgs = new Array();	// 创建坐标信息数组
			this.xArray = new Array();		// 创建分析后的x轴数组
			this.yArray = new Array();		// 创建分析后的y轴数组
		}
		public function onInit(event:Event)	// ”初始化完成“事件侦听器
		{
			if( ExternalInterface.available )	// 如果外部API可用
			{
				ExternalInterface.addCallback( "ClearData", this.clearData );		// 注册回调函数
				ExternalInterface.addCallback( "SetGraphData", this.setGraphData );	// 注册回调函数
				ExternalInterface.call( "SwfIsReady" );// 调用外部函籾，通知SWF已经初始化完成
			}
		}
		public function clearData( ):Boolean			// 清除坐标数组
		{
			this.m_data = null;					// 删除原数组对象，收回内存
			this.m_data = new Array();			// 创建新数组
			return true;
		}
		public function setGraphData( arg:Number ):Number		// 设置坐标数组数据，由外部调用
		{
			this.m_data.push( arg );			// 将坐标数据压入数组
			return 1;
		}
		public function onEnterFrame( event:Event )		// “每一帧”事件侦听器
		{
			if( (this.m_data==null)|| (this.m_data.length == 0) || (this.m_data.length%2 !=0 )  )	// 如果坐标数据为空或根本没有
			{
				return;							// 直接返回
			}
			this.xArray = null;					// 删除x坐标数组，收回内存
			this.yArray = null;					// 删除y坐标数组，收回内存
			this.xArray = new Array();			// 创建分析后的x轴数组	
			this.yArray = new Array();			// 创建分析后的y轴数组
			for( var n:Number = 0; n<this.m_data.length; n++ )		// 从坐标数据数组是提取x，y轴数据
			{
				if( n%2==0 )					// 偶数索引号元素为x轴
				{
					xArray.push( this.m_data[n] );	// 压入分析后的x轴数组	
				}
				else							// 奇数索引号元素为y轴
				{
					yArray.push( this.m_data[n] );	// 压入分析后的y轴数组	
				}	
			}
			for( var i:Number = 0; i<this.m_ptMsgs.length; i++ )	// 将坐标信息标签数组中的每个元互内存收回
			{
				if( this.m_ptMsgs[i] != null )		// 如果当前对象不为空
				{
					try								// 删除它可能发生异常
					{
						this.removeChild( this.m_ptMsgs[i] );		// 先从场景中移除
						delete this.m_ptMsgs[i];					// 再从数组中删除
					}
					catch( e:Error )				
					{
						continue;					// 如果发生异常不与理会，直接下一次循环
					}
				}
			}
			this.graphics.lineStyle( 1, 0xff0000, 1 );				// 设置线形风格
			this.graphics.moveTo( xArray[0],yArray[0] );			// 移到第一个坐标
			var ptMsg0:TextField = new TextField();					// 创建第一个坐标的信息标签
			ptMsg0.text = "(" + String(xArray[0]) + "," + String(yArray[0]) + ")";	// 设置住处文本
			ptMsg0.x = xArray[0];					// 标签x坐标
			ptMsg0.y = yArray[0];					// 标签y坐标
			this.addChild( ptMsg0 );				// 添加到场景
			this.m_ptMsgs.push( ptMsg0 );			// 将引用压入标签数组
			for( var m:Number = 1; m<xArray.length; m++ )	// 逐一为每个坐标创建标签
			{
				this.graphics.lineTo( xArray[m],yArray[m] );// 从上一坐标点画线到当前坐标
				var ptMsg:TextField = new TextField();		// 创建当前坐标标签
				ptMsg.text = "(" + String(xArray[m]) + "," + String(yArray[m]) + ")";	// 设置标签文本
				ptMsg.x = xArray[m];						// 设置标签坐标为当前点坐标
				ptMsg.y = yArray[m];
				this.addChild( ptMsg );				// 将标签添加到场景
				this.m_ptMsgs.push( ptMsg );		// 将标签添加到标签数组
			}
		}
	}
}
