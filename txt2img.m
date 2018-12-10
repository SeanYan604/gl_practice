close all;
filebase = 'tmpcolor';
ext = '.txt';
for i = 1:360
    filename = strcat('./input/',filebase, num2str(i),ext);
    picname = strcat('./output/',filebase,num2str(i),'.png');
    a = load(filename);

%     pos = find(a == -1);
%     a(pos) = 255;

    r = a(1:3:end);
    g = a(2:3:end);
    b = a(3:3:end);
    img = zeros(400,400,3);
    img(:,:,1) = reshape(r,[400,400]);
    img(:,:,2) = reshape(g,[400,400]);
    img(:,:,3) = reshape(b,[400,400]);
    img = uint8(img);

    tmpR = img(:,:,1);
    tmpG = img(:,:,2);
    tmpB = img(:,:,3);

    for j=1:1:400
        img(j,:,1) = tmpR(:,400-j+1);
        img(j,:,2) = tmpG(:,400-j+1);
        img(j,:,3) = tmpB(:,400-j+1);
    end

    figure(1);
    imshow(img);
    imwrite(img,picname);
   
end


