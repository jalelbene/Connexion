//
//first = grand(1,"uin",1,n)
//
//uncovered = points
//covered = [points(first,1), points(first,2)]
//uncovered(first,:) = []
//
//while size(uncovered,"r") <> 0
//    o = 1
//    d = nN(covered(o,1),covered(o,2),uncovered)
//    l_min = Distance(covered(o,1),covered(o,2),uncovered(d,1),uncovered(d,2))
//    for pt = 2:size(covered,"r")
//        n = nN(covered(pt,1),covered(pt,2),uncovered)
//        l = Distance(covered(pt,1),covered(pt,2),uncovered(n,1),uncovered(n,2))
//        if l_min > l then
//            o = pt
//            d = n
//            l_min = l
//        end
//    end
//    x = [covered(o,1),uncovered(d,1)]
//    y = [covered(o,2),uncovered(d,2)]
//    plot(x,y)
//end
//
//
