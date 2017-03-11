<?xml version="1.0" encoding="UTF-8"?>
<!DOCTYPE stylesheet SYSTEM "wwnz_entities.dtd">
<xsl:stylesheet xmlns:xsl="http://www.w3.org/1999/XSL/Transform" version="1.0">

<xsl:import href="common.xsl"/>

<xsl:key name="year" match="/incidents/incident" use="substring-before(dateTime,'-')"/>
<xsl:key name="region" match="/incidents/incident" use="location/region"/>
<xsl:key name="incidentType" match="/incidents/incident" use="type"/>
<xsl:key name="tripType" match="/incidents/incident" use="trip"/>
<xsl:key name="boatType" match="/incidents/incident" use="boat/type"/>
<xsl:key name="incidentTypeModifier" match="/incidents/incident[type = 'Fatal accident']" use="typeModifier"/>
<xsl:key name="class" match="/incidents/incident" use="class"/>

<xsl:template match="/incidents">
  <xsl:call-template name="doIncidentNav"/>

  <xsl:call-template name="doIncidentStatistics"/>
</xsl:template>

<!-- generate some statistics about the database -->
<xsl:template name="doIncidentStatistics">
  <xsl:variable name="numVictims" select="count(/incidents/incident/victim)"/>
  <xsl:variable name="sumVictimsWithAges" select="sum(/incidents/incident/victim/age[. !=''])"/>
  <xsl:variable name="numVictimsWithAges" select="count(/incidents/incident/victim[age != ''])"/>
  <xsl:variable name="avgVictimsAge" select="$sumVictimsWithAges div $numVictimsWithAges"/>

  <table width="100%">
    <tr>
      <th style="width:25%">Incidents in database</th><td style="width:75%"><xsl:value-of select="count(/incidents/incident)"/></td>
    </tr>
    <tr>
      <th>Number of victims</th><td><xsl:value-of select="$numVictims"/></td>
    </tr>
    <tr>
      <th>Average age</th><td><xsl:value-of select="format-number($avgVictimsAge,'#0')"/><!-- <xsl:value-of select="substring-before($avgVictimsAge,'.')"/> --></td>
    </tr>
    <tr>
      <th>Trip Types</th>
      <td>
        <xsl:for-each select="/incidents/incident[generate-id(.)=generate-id(key('tripType',trip))]">
          <xsl:sort select="count(key('tripType',trip))" order="descending" data-type="number"/>
          <!-- <xsl:variable name="tripType" select="trip"/> -->
          <xsl:value-of select="trip"/>&nbsp;<xsl:value-of select="count(key('tripType',trip))"/>
          <xsl:if test="position() != last()">,&nbsp; </xsl:if>
        </xsl:for-each>
      </td>
    </tr>
    <tr>
      <th>Boat Types</th>
      <td>
        <xsl:for-each select="/incidents/incident[generate-id(.)=generate-id(key('boatType',boat/type))]">
          <xsl:sort select="count(key('boatType',boat/type))" order="descending" data-type="number"/>
          <!-- <xsl:variable name="boatType" select="boat/type"/> -->
          <xsl:value-of select="boat/type"/>&nbsp;<xsl:value-of select="count(key('boatType',boat/type))"/>
          <xsl:if test="position() != last()">,&nbsp; </xsl:if>
        </xsl:for-each>
      </td>
    </tr>
    <tr>
      <th>Incident Types</th>
      <td>
        <xsl:for-each select="/incidents/incident[generate-id(.)=generate-id(key('incidentType',type))]">
          <xsl:sort select="count(key('incidentType',type))" order="descending" data-type="number"/>
          <xsl:value-of select="type"/>&nbsp;<xsl:value-of select="count(key('incidentType',type))"/>
          <xsl:if test="position() != last()">,&nbsp; </xsl:if>
        </xsl:for-each>
      </td>
    </tr>
    <tr>
      <th>Fatal Incidents: Type</th>
      <td>
        <xsl:for-each select="/incidents/incident[generate-id(.)=generate-id(key('incidentTypeModifier',typeModifier))]">
          <xsl:sort select="count(key('incidentTypeModifier',typeModifier))" order="descending" data-type="number"/>
          <xsl:value-of select="typeModifier"/>&nbsp;<xsl:value-of select="count(key('incidentTypeModifier',typeModifier))"/>
          <xsl:if test="position() != last()">,&nbsp; </xsl:if>
        </xsl:for-each>
      </td>
    </tr>
    <tr>
      <th>Incident Classes</th>
      <td>
        <xsl:for-each select="/incidents/incident[generate-id(.)=generate-id(key('class',class))]">
          <xsl:sort select="count(key('class',class))" order="descending" data-type="number"/>
          <xsl:value-of select="class"/>&nbsp;<xsl:value-of select="count(key('class',class))"/>
          <xsl:if test="position() != last()">,&nbsp; </xsl:if>
        </xsl:for-each>
      </td>
    </tr>
  </table>
  
  <div style="height: 10em;">&nbsp;</div>
</xsl:template>

</xsl:stylesheet>
