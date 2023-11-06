function S = stiffness_buffered(ord_u, ord_v, force)
    if force == 0
        if ord_u == 0
            if ord_v == 0
                % K_00
                S = [  
                    13/35          9/70         11/210       -13/420;   
                    9/70         13/35         13/420       -11/210;   
                    11/210        13/420         1/105        -1/140;   
                    -13/420       -11/210        -1/140         1/105
                ];   
            elseif ord_v == 1
                % K_01
                S = [   
                    -1/2          -1/2          -1/10          1/10;
                    1/2           1/2           1/10         -1/10; 
                    1/10         -1/10           0            1/60;
                    -1/10          1/10         -1/60           0
                ];
            elseif ord_v == 2
                % K_02
                S = [   
                    -6/5        6/5         -1/10       -1/10;
                    6/5         -6/5        1/10        1/10;
                    -11/10      1/10        -2/15       1/30;
                    -1/10       11/10       1/30        -2/15
                ];
            end
        elseif ord_u == 1
            if ord_v == 0
                % K_10
                S = [
                    -1/2           1/2           1/10         -1/10;
                    -1/2           1/2          -1/10          1/10;
                    -1/10          1/10           0           -1/60;
                    1/10         -1/10          1/60           0
                ];
            elseif ord_v == 1
                % K_11
                S = [
                    6/5          -6/5           1/10          1/10;
                    -6/5           6/5          -1/10         -1/10;
                    1/10         -1/10          2/15         -1/30;
                    1/10         -1/10         -1/30          2/15
                ];
            elseif ord_v == 2
                % K_12
                S = [
                    0             0            -1             1;      
                    0             0             1            -1;     
                    1            -1           -1/2           1/2;     
                    -1             1           -1/2           1/2     
                ];
            end
        elseif ord_u == 2
            if ord_v == 0
                % K_20
                S = [
                    -6/5           6/5         -11/10         -1/10;
                    6/5          -6/5           1/10         11/10;    
                    -1/10          1/10         -2/15          1/30;    
                    -1/10          1/10          1/30         -2/15   
                ];
            elseif ord_v == 1
                % K_21
                S = [
                       0             0             1            -1;      
                       0             0            -1             1;      
                      -1             1           -1/2          -1/2;     
                       1            -1            1/2           1/2     
                ];
            elseif ord_v == 2
                % K_22
                S = [
                      12            -12            6             6;      
                      -12           12            -6            -6;      
                       6            -6             4             2;     
                       6            -6             2             4          
                ];
            end
        end
    elseif force == 1
        if ord_u == 0
            if ord_v == 0
                % K_00x
                S = [  
                      3/35          9/140         1/60         -1/70;    
                      9/140         2/7           1/60         -1/28;    
                      1/60          1/60          1/280        -1/280;   
                     -1/70         -1/28         -1/280         1/168   
                ];   
            elseif ord_v == 1
                % K_01x
                S = [
                    -13/70        -11/35         -3/70          2/35;    
                     13/70         11/35          3/70         -2/35;    
                     -1/105       -31/420        -1/210         1/84;    
                    -11/420        23/210        -1/210        -1/210       
                ];
            elseif ord_v == 2
                % K_02x
                S = [
                     -1/10         11/10           0           -1/10;    
                      1/10        -11/10           0            1/10;    
                     -1/5           1/5          -1/30           0;      
                      1/10          9/10          1/30         -1/10        
                ];
            end
        elseif ord_u == 1
            if ord_v == 0
                % K_10x
                S = [
                    -13/70         13/70         -1/105       -11/420;   
                    -11/35         11/35        -31/420        23/210;   
                     -3/70          3/70         -1/210        -1/210;   
                      2/35         -2/35          1/84         -1/210   
                ];
            elseif ord_v == 1
                % K_11x
                S = [
                      3/5          -3/5           1/10           0;      
                     -3/5           3/5          -1/10           0;      
                      1/10         -1/10          1/30         -1/60;    
                       0             0           -1/60          1/10        
                ];
            elseif ord_v == 2
                % K_12x
                S = [
                     -3/5           3/5          -3/10          7/10;    
                      3/5          -3/5           3/10         -7/10;    
                      1/5          -1/5          -1/15          4/15;    
                     -4/5           4/5          -7/30         13/30        
                ];
            end
        elseif ord_u == 2
            if ord_v == 0
                % K_20x
                S = [                
                     -1/10          1/10         -1/5           1/10;    
                     11/10        -11/10          1/5           9/10;    
                       0             0           -1/30          1/30;    
                     -1/10          1/10           0           -1/10        
                ];
            elseif ord_v == 1
                % K_21x
                S = [
                     -3/5           3/5           1/5          -4/5;     
                      3/5          -3/5          -1/5           4/5;     
                     -3/10          3/10         -1/15         -7/30;    
                      7/10         -7/10          4/15         13/30    
                ];
            elseif ord_v == 2
                %K_22x
                S = [
                     6    -6     2     4;
                    -6     6    -2    -4;
                     2    -2     1     1;
                     4    -4     1     3
                ];
            end
        end
    end
end