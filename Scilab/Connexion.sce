//getf('test.sce')


//for k = 2:n
//    nN = points(1,:)
//    for pt = 2:k-1
//        if Distance([points(k,:)],[nN]) > Distance([points(k:)],[points(pt:,)]) then
//            nN = points(pt:,)
//        end
//    end
//    plot(points(k,:),nN)
//end


//for k = 2:n
//    nN = 1
//    d_min = Distance(points(nN,1),points(nN,2),points(k,1),points(k,2))
//    for pt = 2:k-1
//        d = Distance(points(pt,1),points(pt,2),points(k,1),points(k,2))
//        if d_min > d then
//            nN = pt
//            d_min = d
//        end
//    end
//    x = [points(k,1),points(nN,1)]
//    y = [points(k,2),points(nN,2)]
//    plot(x,y)
//end



for k = 2:n
    previous = points(1:k-1,:)
    funcprot(0)
    n = nN(points(k,1), points(k,2),previous)
    x = [points(k,1),points(n,1)]
    y = [points(k,2),points(n,2)]
    plot(x,y)
end
