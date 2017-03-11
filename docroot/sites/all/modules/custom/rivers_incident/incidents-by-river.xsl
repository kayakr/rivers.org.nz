<?xml version="1.0" encoding="UTF-8"?>
<!DOCTYPE stylesheet SYSTEM "wwnz_entities.dtd">
<xsl:stylesheet xmlns:xsl="http://www.w3.org/1999/XSL/Transform" version="1.0">

<xsl:import href="common.xsl"/>

<xsl:template match="/incidents">
  <xsl:call-template name="doIncidentNav"/>

  <p>List all incidents by River (<xsl:value-of select="count(/incidents/incident)"/>)</p>

  <table>
    <tr>
      <th>River</th>
      <th>Date</th>
      <th>Type</th>
      <th>Incident</th>
    </tr>

    <xsl:apply-templates select="incident">
      <xsl:sort select="concat(location/river,location/section)" order="ascending"/>
    </xsl:apply-templates>
  </table>
</xsl:template>

<xsl:template match="incident">
  <tr>
    <td><xsl:value-of select="location/river"/></td>
    <td><xsl:value-of select="substring-before(dateTime,'T')"/></td>
    <td><xsl:value-of select="type"/></td>
    <td>
<!--  <xsl:value-of select="type"/> (<xsl:value-of select="substring-before(dateTime,'T')"/>): -->
    <a title="View details of incident {@id}" href="/safety/db/incident/{@id}">
    <xsl:for-each select="victim">
      <xsl:value-of select="nationality"/>,<xsl:if test="age"> <xsl:value-of select="age"/>,</xsl:if>
    </xsl:for-each>
    <xsl:value-of select="location/region"/>/<xsl:value-of select="location/river"/><xsl:if test="location/river != location/section">/<xsl:value-of select="location/section"/></xsl:if>
    </a>
    </td>
  </tr>
</xsl:template>

</xsl:stylesheet>