
TASK
-----------

Generate simple report basing on given HTML file "currentsets.html".
This HTML file contains information about OMS targets in the form:
"""
<tr class="description">
<td>Target name</td>
<td>description</td>
<td>Target IP</td>
<td>Product</td>
<td>Currentset</td>
<td>Logged users</td>
<td>Uptime</td>
<td>Currentset update time</td>
<td>SWBIT</td>
<td>HW type</td>
<td>owner</td>
</tr>

<tr>
<td>Faraday</td>
<td>HPOMS-01</td>
<td>10.121.85.21</td>
<td>rnc </td>
<td>R_GOMS6_1.31.1.0.release_oms.corr34</td>
<td> 0 users</td>
<td>5 days, 5:02</td>
<td>Mon Oct 24 08:45:04 CEST 2011</td>
<td></td>
<td>HP</td>
<td>Mariusz Irla</td></tr>
"""

You can use prepared template `currentset.py`, where module has already
needed functions, which should be completed with your code.

Required steps:

1. Parse HTML

In the template there is already `parse` function, which iterates over `tr` html elements,
thus table records with data needed for report.
It should be modified that it will return data, which function `report` will use
for generating report.

2. Generate report 

Modify function `report` that it will generate report to standard output.
Report should contain only records with some value in HW_TYPE column.
All records should be sorted by columns: HW_TYPE, Target_name
Report should have following form:

<HW type>

<Target name> <Target IP>
<Target name> <Target IP>
...
<Target name> <Target IP>

<HW type>

<Target name> <Target IP>
<Target name> <Target IP>
...
<Target name> <Target IP>

...


e.g.:


========== BLADE ==========
Aries 10.121.89.152
Corvus 10.121.88.20
===========================
========== HP ==========
Braille 10.121.88.128
Cassini 10.121.85.35
========================



TIPS
---------

1. For HTML parsing there was used library `ElementSoup`, which uses `ElementTree` internally,
so this documentation describes API of this module:
http://docs.python.org/2/library/xml.etree.elementtree.html

2. For sorting consider using parameter `key`

3. For grouping HW_TYPEs consider using `itertools.groupby` function
