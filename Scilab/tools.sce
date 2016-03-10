
n = 250

points = grand(n,2,'def')

//function d = Distance(A,B)
//    d = sqrt((A(1)-B(1))^2 + (A(2)-B(2))^2);
//endfunction


function d = Distance(x1,y1,x2,y2)
    d = sqrt((x1-x2)^2 + (y1-y2)^2);
endfunction


function n = nN(pt_x, pt_y,list)
    n = 1
    d_min = Distance(pt_x, pt_y,list(n,1),list(n,2))
    for k = 2:size(list, "r")
        d = Distance(pt_x, pt_y,list(k,1),list(k,2))
        if d_min > d then
            n = k
            d_min = d
        end
    end
endfunction
