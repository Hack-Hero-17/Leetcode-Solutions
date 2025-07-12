/**
 * @param {string[]} list1
 * @param {string[]} list2
 * @return {string[]}
 */
var findRestaurant = function(list1, list2) {
    const map = new Map();
    list1.forEach((word, i) => map.set(word, i));

    let minSum = Infinity;
    const result = [];

    list2.forEach((word, j) => {
        if (map.has(word)) {
            const indexSum = j + map.get(word);
            if (indexSum < minSum) {
                minSum = indexSum;
                result.length = 0;
                result.push(word);
            } else if (indexSum === minSum) {
                result.push(word);
            }
        }
    });

    return result;
};