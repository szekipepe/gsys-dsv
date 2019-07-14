#ifndef GSYS_DSV_CONFIG_H
#define GSYS_DSV_CONFIG_H

namespace GSys {

namespace DSV {

    /*! \brief DSV Parser config
     */
    class Config {
    public:
        /*! brief Supported line endings
         */
        enum class LineEnding {
            Lf, //<! Linux, Mac OS X, default
            CrLf, //<! Windows
            Cr //<! old Mac
        };

        static constexpr auto LfLineEnding = "\n";
        static constexpr auto CrLfLineEnding = "\r\n";
        static constexpr auto CrLineEnding = "\r";

        /*! Supported delimiters
         */
        enum class Delimiter {
            Comma, //<! Default
            Colon,
            Pipe,
            Semicolon,
            Tab
        };

        static constexpr auto CommaDelimiter = ',';
        static constexpr auto ColonDelimiter = ':';
        static constexpr auto PipeDelimiter = '|';
        static constexpr auto SemiColonDelimiter = ';';
        static constexpr auto TabDelimiter = '\t';

        /*! Supported text data restrictions
         */
        enum class AllowedTextData {
            All, //<! Default, anything allowed between double quotes
            Rfc4180 //<! text data characters is %x20-21 / %x23-2B / %x2D-7E (only)
        };

        /*! \brief Supported header modes
         */
        enum class Header {
            NoHeader,
            FirstLineHeader //<! Default
        };

    public:
        Config() = default;

        auto lineEnding() const { return m_line_ending; }
        void setLineEnding(LineEnding value) { m_line_ending = value; }

        auto delimiter() const { return m_delimiter; }
        // void setDelimiter(Delimiter value) { m_delimiter = value; }

        auto allowedTextData() const { return m_allowed_text_data; }
        // void setAllowedTextData(AllowedTextData value) { m_strict = value; }

        auto header() const { return m_header; }
        // void setHeader(Header value) { m_header = value; }

    private:
        LineEnding m_line_ending = LineEnding::Lf;
        Delimiter m_delimiter = Delimiter::Comma;
        AllowedTextData m_allowed_text_data = AllowedTextData::All;
        Header m_header = Header::FirstLineHeader;
    };

} // namespace DSV

} // namespace GSys

#endif // GSYS_DSV_CONFIG_H
