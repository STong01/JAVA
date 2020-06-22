        [x,y,z]=peaks;
        subplot(1,2,1)       
        contour3(x,y,z,16,'s')   
        grid,   xlabel('x-axis'),  ylabel('y-axis')
        zlabel('z-axis')
        title('contour3 of peaks'); 
        subplot(1,2,2)
        [c,h]=contour(z,3,'s')
        clabel(c,h)
        grid,   xlabel('x-axis'),    ylabel('y-axis')
        title('contour of peaks');