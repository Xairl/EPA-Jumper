function x_int = float_to_uint(x, x_min, x_max, bits)
    % Converts a float to an unsigned int, given range and number of bits %
    span = x_max - x_min;
    offset = x_min;
    x_int = uint16((x - offset) * (double((2^bits) - 1)) / span);
end