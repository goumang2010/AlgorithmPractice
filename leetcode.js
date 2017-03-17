var uniquePathsWithObstacles = function(obstacleGrid) {
    var calPath = function(m, n) {
        var _m = m - 1;
        var _n = n - 1;
        var all = _m + _n;
        if(_m > _n) {
            _m = _n;
        }
        var res = 1;
        for(var i = 0;i < _m; i++) {
            res *= (all - i) / (_m - i);
        }
        return res;
    }
    var w = obstacleGrid[0].length;
    var h = obstacleGrid.length;
    var allps = calPath(w, h);
    var obs = [];
    for(var j = 0; j < h; j++) {
         for(var k = 0; k < w; k++) {
             if(obstacleGrid[j][k] === 1) {
                 allps = allps - calPath(k + 1, j + 1);
                 allps = allps - calPath(w - k, h -j);
                 for(var p=0, ol = obs.length; p < ol;p++) {
                     var pre = obs[p];
                     allps += calPath(k - pre.k, j - pre.j)
                 }
                 obs.push({j:j, k: k})
             }
         }
    }
    return allps;
};