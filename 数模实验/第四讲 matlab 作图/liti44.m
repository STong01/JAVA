m=moviein(20); %����һ��20����������ɵľ���
for j=1:20
   plot(fft(eye(j+10)))% ���Ƴ�ÿһ������ͼ�����浽m������
   m(:,j)=getframe;
end
movie(m,10)