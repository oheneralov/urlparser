(function(module){
var URLFactory = function($http){
    var factory = {};
    var result;
    factory.getURL = function(url){
        return $http.get('parseurl.json');
    }
    return factory;

}


module.factory("URLFactory", URLFactory);
}(angular.module("app")));
