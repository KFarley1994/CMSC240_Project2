import QtQuick 2.0

import "."
import "QChart.js"        as Charts
import "QChartGallery.js" as ChartsData

Chart {
  id: chart_bar;
  width: 450;
  height: 450;
  chartAnimated: false;
  chartData: ChartsData.ChartBarData;
  chartType: Charts.ChartType.BAR;
}