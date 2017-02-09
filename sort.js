function quicksort(mangleArr, left = 0, right = mangleArr.length - 1) {
    console.log('---------');
    console.log('array is: ' + mangleArr);
    console.log('left is: ' + left);
    console.log('right is: ' + right);
    console.log('---------');
    if ((right - left) <= 1) {
        switchPos(left, right, mangleArr);
        return mangleArr;
    }
    let _right = right;
    let _left = left;
    let _array = mangleArr;

    // establish two flag
    let mid = Math.ceil((left + right) / 2);
    switchPos(_left, mid, _array);
    switchPos(_left, _right, _array);
    switchPos(mid, _right, _array);
    let pivot = _array[mid];
    switchPos(mid, _right - 1, _array, true);
    _right -= 2;
    _left++;
    let checkArray = function () {
        while (_array[_left] < pivot) {
            _left++;
        }

        while (_array[_right] > pivot) {
            _right--;
        }

        if (_left < _right) {
            switchPos(_left, _right, _array);
            checkArray();
        }
    }
    checkArray();
    switchPos(_left, right - 1, _array, true);
    console.log('now the mid is: ' + _right);
    quicksort(_array, left, _left - 1);
    quicksort(_array, _left + 1, right);
    return _array;
}


function switchPos(a, b, _array, force = false) {
    if (_array[a] > _array[b] || force) {

        let temp = _array[a];
        _array[a] = _array[b];
        _array[b] = temp;
        console.log('switch ' + a + ' and ' + b + ', array now: ' + _array);

        return true;
    } else {
        return false;
    }
}