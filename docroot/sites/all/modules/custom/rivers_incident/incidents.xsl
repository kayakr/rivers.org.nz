<?xml version="1.0" encoding="UTF-8"?>
<!DOCTYPE stylesheet SYSTEM "wwnz_entities.dtd">
<xsl:stylesheet xmlns:xsl="http://www.w3.org/1999/XSL/Transform" version="1.0">

<xsl:import href="common.xsl"/>

<xsl:key name="year" match="/incidents/incident" use="substring-before(dateTime,'-')"/>
<xsl:key name="region" match="/incidents/incident" use="location/region"/>
<!-- <xsl:key name="incidentType" match="/page/content/article/incidents/incident" use="type"/>
<xsl:key name="tripType" match="/page/content/article/incidents/incident" use="trip"/>
<xsl:key name="boatType" match="/page/content/article/incidents/incident" use="boat/type"/>
<xsl:key name="incidentTypeModifier" match="/page/content/article/incidents/incident[type = 'Fatal accident']" use="typeModifier"/>
<xsl:key name="class" match="/page/content/article/incidents/incident" use="class"/> -->

<xsl:template match="/incidents">
  <xsl:call-template name="doIncidentNav"/>

  <p><em>The Whitewater NZ Accident/Incident database is intended to be a definitive record of whitewater kayak and canoe incidents, published in order to raise awareness of risks among the recreational canoeing community.</em></p>

  <xsl:call-template name="incidents"/>

  <xsl:choose>
    <xsl:when test="$year != ''">
      <xsl:call-template name="doListForYear"/>
    </xsl:when>

    <xsl:when test="$region != ''">
      <xsl:call-template name="doListForRegion"/>
    </xsl:when>

    <xsl:otherwise>
      <xsl:call-template name="doShowIncidents"/>
    </xsl:otherwise>
  </xsl:choose>

</xsl:template>

<xsl:template name="incidents">
  <div style="background: #cccccc; padding: 2px 2px 3px 2px; margin: 5px 0px 0px 0px;">
    <!-- <xsl:value-of select="count(incident)"/> incidents in database. -->
  
  <table style="width:80%">
    <tr>
      <th style="width:50%">Year</th>
      <th style="width:50%">Region</th>
    </tr>
    <tr>
      <td style="vertical-align:top;">
        <!-- work out what years we have, then count them -->
        <xsl:for-each select="incident[generate-id(.)=generate-id(key('year',substring-before(dateTime,'-')))]">
          <xsl:sort select="substring-before(dateTime,'-')" order="descending" data-type="number"/>
          <xsl:variable name="year" select="substring-before(dateTime,'-')"/>
          <a href="/safety/db/year/{$year}" title="List incidents for the year {$year}">
            <xsl:value-of select="$year"/>
          </a> (<xsl:value-of select="count(key('year',$year))"/>)<br/>
        </xsl:for-each>
      </td>
      <td style="vertical-align:top;">
        <xsl:call-template name="linkToRegion"><xsl:with-param name="region">Northland &amp; Auckland</xsl:with-param></xsl:call-template><br/>
        <xsl:call-template name="linkToRegion"><xsl:with-param name="region">Waikato &amp; Bay of Plenty</xsl:with-param></xsl:call-template><br/>
        <xsl:call-template name="linkToRegion"><xsl:with-param name="region">Gisborne &amp; Hawkes Bay</xsl:with-param></xsl:call-template><br/>
        <xsl:call-template name="linkToRegion"><xsl:with-param name="region">Taranaki &amp; Wanganui</xsl:with-param></xsl:call-template><br/>
        <xsl:call-template name="linkToRegion"><xsl:with-param name="region">Wellington &amp; Manawatu</xsl:with-param></xsl:call-template><br/>
        <xsl:call-template name="linkToRegion"><xsl:with-param name="region">Tasman &amp; Marlborough</xsl:with-param></xsl:call-template><br/>
        <xsl:call-template name="linkToRegion"><xsl:with-param name="region">West Coast</xsl:with-param></xsl:call-template><br/>
        <xsl:call-template name="linkToRegion"><xsl:with-param name="region">Canterbury</xsl:with-param></xsl:call-template><br/>
        <xsl:call-template name="linkToRegion"><xsl:with-param name="region">Otago</xsl:with-param></xsl:call-template><br/>
        <xsl:call-template name="linkToRegion"><xsl:with-param name="region">Southland</xsl:with-param></xsl:call-template>
      </td>
    </tr>
  </table>
  </div>
  
  <!-- <xsl:apply-templates select="incident"/> -->
</xsl:template>

<xsl:variable name="pageTitleForBreadcrumb"><xsl:choose>
  <xsl:when test="/page/content/action/year">List for Year = <xsl:value-of select="/page/content/action/year"/></xsl:when>
  <xsl:when test="/page/content/action/region">List for Region = <xsl:value-of select="/page/content/action/region"/></xsl:when>
  <xsl:otherwise></xsl:otherwise></xsl:choose></xsl:variable>

<!-- want to set page Changed date to that of the most recently changed Incident record -->
<!-- <xsl:variable name="myChanged">
  @@@@@OurOwnValue -->
  <!-- <xsl:apply-templates select="/page/content/article/incidents/incident[1]" mode="find-max" /> -->
<!-- </xsl:variable> -->

<!-- <xsl:template match="incident" mode="find-max">
   <xsl:variable name="next" select="following-sibling::incident[changed &gt; current()/changed]" />
   <xsl:choose>
      <xsl:when test="$next">
         <xsl:apply-templates select="$next" mode="find-max" />
      </xsl:when>
      <xsl:otherwise>
         <xsl:value-of select="changed" />
      </xsl:otherwise>
   </xsl:choose>
</xsl:template> -->

<!-- override pageInfo, since we want the 'changed' value to be derived from the incidents .xml file -->
<!-- <xsl:template name="doPageInfo">
  Created: <xsl:value-of select="$created"/>, updated: <xsl:value-of select="substring-before($myChanged,'T')"/>.<br />
  Identifier: http://<xsl:value-of select="/page/globals/identifier"/>
</xsl:template> -->

<xsl:template name="linkToRegion">
  <xsl:param name="region"/>
  <!-- are we dealing with one or two regions -->
  <xsl:choose>
    <xsl:when test="contains($region,' &amp; ')">
      <xsl:variable name="region1"><xsl:value-of select="substring-before($region,' &amp;')"/></xsl:variable>
      <xsl:variable name="region2"><xsl:value-of select="substring-after($region,'&amp; ')"/></xsl:variable>
      <!-- region1=<xsl:value-of select="$region1"/>,region2=<xsl:value-of select="$region2"/><br/> -->
      <xsl:choose>
        <xsl:when test="count(key('region',$region1))+count(key('region',$region2)) != 0">
        <a href="/safety/db/region/{$region1} and {$region2}" title="List incidents for {$region}">
          <xsl:value-of select="$region"/>
        </a> (<xsl:value-of select="count(key('region',$region1))+count(key('region',$region2))"/>)
    </xsl:when>
    <xsl:otherwise><xsl:value-of select="$region"/></xsl:otherwise>
  </xsl:choose>
    </xsl:when>
    <xsl:otherwise>
      <!-- single region=<xsl:value-of select="$region"/><br/> -->
      <xsl:choose>
        <xsl:when test="count(key('region',$region)) != 0">
          <a href="/safety/db/region/{$region}" title="List incidents for {$region}">
            <xsl:value-of select="$region"/>
          </a> (<xsl:value-of select="count(key('region',$region))"/>)
        </xsl:when>
        <xsl:otherwise><xsl:value-of select="$region"/></xsl:otherwise>
      </xsl:choose>
    </xsl:otherwise>
  </xsl:choose>
  
</xsl:template>

<xsl:template name="doListForYear">
<!-- set via incidents.module  <xsl:variable name="year" select="/page/content/action/year"/> -->
  <p>List for Year = <xsl:value-of select="$year"/> (<xsl:value-of select="count(/incidents/incident[substring-before(dateTime,'-') = $year])"/> incidents)</p>
  
  <xsl:for-each select="/incidents/incident[substring-before(dateTime,'-') = $year]">
    <xsl:sort select="dateTime" order="descending"/>
    <xsl:apply-templates select="." mode="compressedList"/>
  </xsl:for-each>
</xsl:template>

<!-- List all incidents, either by Year or River -->
<!-- <xsl:template name="doList">
  <xsl:choose>
    <xsl:when test="/page/content/action/list = 'year'">
      <p>List all incidents by Year (<xsl:value-of select="count(incidents/incident)"/>)</p>
      <xsl:for-each select="incidents/incident">
        <xsl:sort select="dateTime" order="descending"/>
        <xsl:apply-templates select="." mode="compressedList"/>
      </xsl:for-each>
    </xsl:when>
    <xsl:when test="/page/content/action/list = 'river'">
      <p>List all incidents by River (<xsl:value-of select="count(incidents/incident)"/>)</p>
      <xsl:for-each select="incidents/incident">
        <xsl:sort select="concat(location/river,location/section)" order="ascending"/>
        <xsl:apply-templates select="." mode="compressedList"/>
      </xsl:for-each>
    </xsl:when>
    <xsl:otherwise>
      <p>Can only list by Year or River.</p>
    </xsl:otherwise>
  </xsl:choose>
</xsl:template> -->

<!-- are we dealing with one or two regions -->
<xsl:template name="doListForRegion">
  <p>List for Region = <xsl:value-of select="$region"/>
  
    <xsl:choose>  
      <xsl:when test="contains($region,' &amp; ')">
        <xsl:variable name="region1"><xsl:value-of select="substring-before($region,' &amp;')"/></xsl:variable>
        <xsl:variable name="region2"><xsl:value-of select="substring-after($region,'&amp; ')"/></xsl:variable>
        (<xsl:value-of select="count(/incidents/incident[location/region = $region1]) + count(/incidents/incident[location/region = $region2])"/> incidents)
      </xsl:when>
      <xsl:otherwise>
        (<xsl:value-of select="count(/incidents/incident[location/region = $region])"/> incidents)
      </xsl:otherwise>
    </xsl:choose>
  </p>
  
  <xsl:choose>
    <xsl:when test="contains($region,' &amp; ')">
      <xsl:variable name="region1"><xsl:value-of select="substring-before($region,' &amp;')"/></xsl:variable>
      <xsl:variable name="region2"><xsl:value-of select="substring-after($region,'&amp; ')"/></xsl:variable>
      <xsl:for-each select="/incidents/incident[location/region=$region1 or location/region=$region2]">
        <xsl:sort select="dateTime" order="descending"/>
        <xsl:apply-templates select="." mode="compressedList"/>
      </xsl:for-each>
    </xsl:when>
    <xsl:otherwise>
      <xsl:for-each select="/incidents/incident[location/region = $region]">
        <xsl:sort select="dateTime" order="descending"/>
        <xsl:apply-templates select="." mode="compressedList"/>
      </xsl:for-each>
    </xsl:otherwise>
  </xsl:choose>
  
</xsl:template>

<xsl:template name="doShowIncidents">
  <h3>Recently added or updated incidents:</h3>
  
  <p>
  <xsl:apply-templates select="/incidents/incident" mode="compressedListLimited">
    <xsl:sort select="changed" order="descending"/>
  </xsl:apply-templates>
  </p>
</xsl:template>

<xsl:template match="incident" mode="compressedListLimited">
  <xsl:if test="position() &lt; 11">
    <xsl:apply-templates select="." mode="compressedList"/>
  </xsl:if>
</xsl:template>

<xsl:template match="incident" mode="compressedList">
   <xsl:value-of select="type"/> (<xsl:value-of select="substring-before(dateTime,'T')"/>): 
    <a title="View details of incident {@id}" href="/safety/db/incident/{@id}">
    <xsl:for-each select="victim">
      <xsl:value-of select="nationality"/>,<xsl:if test="age"> <xsl:value-of select="age"/>,</xsl:if>
    </xsl:for-each>
    <xsl:value-of select="location/region"/>/<xsl:value-of select="location/river"/><xsl:if test="location/river != location/section">/<xsl:value-of select="location/section"/></xsl:if></a>
  <br/>
</xsl:template>

<xsl:template match="summary|discussion">
  <xsl:apply-templates select="p|q|img"/>
</xsl:template>

<xsl:template name="doBody">
  <xsl:apply-templates select="body"/>
  <xsl:apply-templates select="incidents"/>
  <br/>
  <xsl:choose>
    <xsl:when test="/page/content/action/year">
      <xsl:call-template name="doListForYear"/>
    </xsl:when>
    <xsl:when test="/page/content/action/region">
      <xsl:call-template name="doListForRegion"/>
    </xsl:when>
    
    <xsl:otherwise>
      <!-- show most recently modified incidents -->
      <xsl:call-template name="doShowIncidents"/>
    </xsl:otherwise>
  </xsl:choose>
</xsl:template>

</xsl:stylesheet>
