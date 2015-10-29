/**
 * Created by Oleksandr_Generalov on 10/29/2015.
 */
(function (module) {
    var generalController = function ($scope, $http) {
        $scope.parseUrl = function (urltoparse) {
            console.log("res: " + urltoparse);

            $http.get('parseurl.php?url=' + urltoparse).then(function (response) {
                //console.log(response.data);
                $scope.parsedUrl = response;
                console.log(response);
                return response;
            });

        }
    };

    module.controller("generalController", generalController);


}(angular.module("app")));