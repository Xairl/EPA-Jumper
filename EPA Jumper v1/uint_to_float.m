function x = uint_to_float(x_int, x_min, x_max, bits)
    % Converts an unsigned int to float, given range and number of bits %
    span = x_max - x_min;
    offset = x_min;
    x = double(x_int) * span / double((2^bits) - 1) + offset;
end