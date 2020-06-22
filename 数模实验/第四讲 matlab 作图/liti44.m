m=moviein(20); %建立一个20个列向量组成的矩阵
for j=1:20
   plot(fft(eye(j+10)))% 绘制出每一幅眼球图并保存到m矩阵中
   m(:,j)=getframe;
end
movie(m,10)