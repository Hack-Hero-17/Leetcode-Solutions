/**
 * @param {number} n
 * @return {number}
 */
var trailingZeroes = function(n) {
    let count = 0, divisor = 5;
    while (n >= divisor) {
        count += Math.floor(n / divisor);
        divisor *= 5;
    }
    return count;
};