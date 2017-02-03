/**
 * Created by Oleksandr_Generalov on 10/29/2015.
 */
(function (module) {
    var generalController = function ($scope, URLFactory) {
        $scope.parseUrl = function (urltoparse) {
        $scope.parsedUrl = URLFactory.getURL(urltoparse).then(function(response){
             $scope.parsedUrl = response.data;
             console.log("result:");
             console.log(response)
        }
        );

        }
    };

    module.controller("generalController", generalController);


}(angular.module("app")));
