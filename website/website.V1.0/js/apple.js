AmCharts.loadJSON = function(url) {
              // create the request
              if (window.XMLHttpRequest) {
                // IE7+, Firefox, Chrome, Opera, Safari
                var request = new XMLHttpRequest();
              } else {
                // code for IE6, IE5
                var request = new ActiveXObject('Microsoft.XMLHTTP');
              }

              // load it
              // the last "false" parameter ensures that our code will wait before the
              // data is loaded
              request.open('GET', url, false);
              request.send();

              // parse adn return the output
              return eval(request.responseText);
            };
			

			// load the data
            var chartData = AmCharts.loadJSON('apple.php');

			AmCharts.makeChart("container", {
				type: "stock",
				pathToImages: "images/",

				dataSets: [{
					fieldMappings: [{
						fromField: "open",
						toField: "open"
					}, {
						fromField: "close",
						toField: "close"
					}, {
						fromField: "high",
						toField: "high"
					}, {
						fromField: "low",
						toField: "low"
					}, {
						fromField: "volume",
						toField: "volume"
					}, {
						fromField: "value",
						toField: "value"
					}],

					color: "#7f8da9",
					dataProvider: chartData,
					title: "West Stock",
					categoryField: "date"
				}, {
					fieldMappings: [{
						fromField: "value",
						toField: "value"
					}],
					color: "#fac314",
					dataProvider: chartData,
					compared: true,
					title: "East Stock",
					categoryField: "date"
				}],


				panels: [{
						title: "Value",
						showCategoryAxis: false,
						percentHeight: 70,
						valueAxes: [{
							id:"v1",
							dashLength: 5
						}],

						categoryAxis: {
							dashLength: 5,
							//equalSpacing: false//!!-----------
						},

						stockGraphs: [{
							type: "candlestick",
							id: "g1",
							openField: "open",
							closeField: "close",
							highField: "high",
							lowField: "low",
							valueField: "close",
							lineColor: "#7f8da9",
							fillColors: "#7f8da9",
							negativeLineColor: "#db4c3c",
							negativeFillColors: "#db4c3c",
							fillAlphas: 1,
							useDataSetColors: false,
							comparable: true,
							compareField: "value",
							showBalloon: false
						}],

						stockLegend: {
							valueTextRegular: undefined,
							periodValueTextComparing: "[[percents.value.close]]%"
						}
					},

					{
						title: "Volume",
						percentHeight: 30,
						marginTop: 1,
						showCategoryAxis: true,
						valueAxes: [{
							id:"v2",
							dashLength: 5
						}],

						categoryAxis: {
							dashLength: 5,
							//equalSpacing: true
						},

						stockGraphs: [{
							valueField: "volume",
							type: "column",
							showBalloon: false,
							fillAlphas: 1
						}],

						stockLegend: {
							markerType: "none",
							markerSize: 0,
							labelText: "",
							periodValueTextRegular: "[[value.close]]"
						}
					}
				],

				chartCursorSettings: {
					valueLineEnabled:true,
					valueLineBalloonEnabled:true
				},




				chartScrollbarSettings: {
					graph: "g1",
					graphType: "line",
					usePeriod: "WW"
				},

				periodSelector: {
					position: "bottom",
					periods: [{
						period: "DD",
						count: 10,
						label: "10 days"
					}, {
						period: "MM",
						selected: true,
						count: 1,
						label: "1 month"
					}, {
						period: "YYYY",
						count: 1,
						label: "1 year"
					}, {
						period: "YTD",
						label: "YTD"
					}, {
						period: "MAX",
						label: "MAX"
					}]
				}
			});