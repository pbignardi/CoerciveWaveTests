function [] = animate(X, T, U)
    % Animate function
    %   Function to plot a 2 variable function, in moving 
    %   time variable t.
    
    %% Parameters
    % The number of time steps is given by the number of rows of U
    n_tsteps = size(U,1);

    % Frame rate
    duration_mult = 2;
    fps = 24;
    T_max = max(max(T));

    actual_duration = n_tsteps / fps;
    target_nframes = duration_mult * T_max * fps;
    skip_nframes = floor(size(T, 1) / target_nframes);
    
    frames = 1:skip_nframes:size(T,1);

    % U_lims
    u_min = min(min(U));
    u_max = max(max(U));

    % x_lims 
    x_min = min(min(X));
    x_max = max(max(X));

    

    %% Plotting
    % Plot each row of U
    for f = frames
        x = X(f, :);
        u = U(f, :);
        plot(x, u);
        axis([x_min x_max u_min u_max]);
        grid on;
        drawnow
        pause(1/fps);
        %exportgraphics(gcf,"solution.gif","Append", true);
    end

end