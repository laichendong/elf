/**
 * User: laichendong
 * Date: 13-9-10
 * Time: 上午9:15
 */
(function ($) {
    /**
     * 分页条构造函数
     * @constructor
     */
    function ElfPagination(container, options) {
        if (options.totalPage <= 0) {
            throw new Error("非法的参数值:totalPage=" + options.totalPage + "，totalPage应该为正整数。")
        }
        this._container = container;
        this._o = options;

        var elfId = new Date().getTime();
        this._container.data("elf_id", elfId);
        $.elfPagination[elfId] = this;
        this._init();
    }

    /**
     * 扩展分页条原型对象
     */
    $.extend(ElfPagination.prototype, {
        /**
         * 跳转到某一页
         * @param page 要跳转到的页
         * @returns {*}
         */
        goToPage: function (page) {
            page = parseInt(page);
            page = (page < 1) ? 1 : page;
            page = (page > this._o.totalPage) ? this._o.totalPage : page;
            this._o.index = page;
            this._render();
            // 执行回调
            this._o.paged(page);
        },

        /**
         * 上一页
         */
        prevPage: function () {
            this.goToPage(--this._o.index);
        },

        /**
         * 下一页
         */
        nextPage: function () {
            this.goToPage(++this._o.index);
        },

        /**
         * 初始化分页条
         * @private
         */
        _init: function () {
            // 生成html结构
            this._render();
            // 绑定交互事件
            this._bindEvent();

        },

        /**
         * 渲染界面
         * @private
         */
        _render: function () {
            this._container.empty();
            // 上一页
            if (this._o.showPrevAndNext) {
                this._container.append('<a href="javascript:void(0)" class="pre ' + (this._o.index == 1 ? "disabled" : "") + '">&nbsp;</a>');
            }
            // 页码
            this._renderPages();
            // 下一页
            if (this._o.showPrevAndNext) {
                this._container.append('<a href="javascript:void(0)" class="next ' + (this._o.index == this._o.totalPage ? "disabled" : "") + '">&nbsp;</a>');
            }
            // 总页数
            if (this._o.totalPage) {
                this._container.append('<span>共' + this._o.totalPage + '页</span>');
            }
            // 跳页功能
            if (this._o.showGoTo) {
                this._container.append('<label><span>到</span><input type="text" class="go-to" value="' + this._o.index + '"><span>页</span></label>' +
                    '<input type="button" class="go" value="确定">');
            }
        },

        /**
         * 渲染页码部分
         * @private
         */
        _renderPages: function () {
            var isEdge, isSibling, isCurr, first, last, ellipse, ellipseAppended = false;
            for (var page = 1; page <= this._o.totalPage; page++) {
                first = (page == 1 ? "first" : "");
                last = (page == this._o.totalPage ? "last" : "");
                isEdge = (page <= this._o.numEdge) || (page >= this._o.totalPage - this._o.numEdge + 1);
                isSibling = (page >= this._o.index - this._o.numSiblings && page < this._o.index)
                    || (page > this._o.index && page <= this._o.index + this._o.numSiblings);
                isCurr = (page == this._o.index);
                ellipse = (page > this._o.numEdge && page < this._o.index - this._o.numSiblings)
                    || (page > this._o.index + this._o.numSiblings && page <= this._o.totalPage - this._o.numEdge);
                if (isEdge || isSibling || isCurr) {
                    this._container.append('<a href="javascript:void(0)" class="page ' + first + ' ' + last + ' ' + (isCurr ? "curr" : "") + '" page="' + page + '">' + page + '</a>');
                    ellipseAppended = false;
                } else {
                    if (ellipse && !ellipseAppended) {
                        this._container.append('<span>...</span>');
                        ellipseAppended = true;
                    }
                }
            }
        },

        /**
         * 绑定交互事件
         * @private
         */
        _bindEvent: function () {
            var _this = this;
            var container = _this._container;
            container
                .delegate(".page", "click",function () { // 点击页码
                    if ($(this).hasClass("curr")) {
                        return;
                    }
                    _this.goToPage($(this).attr("page"));
                }).delegate(".pre,.next", "click",function () { // 点击“上一页”“下一页”
                    if ($(this).hasClass("disabled")) {
                        return;
                    }
                    var curr = container.find(".curr");
                    if ($(this).hasClass("pre") && !curr.hasClass("first")) {
                        _this.prevPage();
                    } else if ($(this).hasClass("next") && !curr.hasClass("last")) {
                        _this.nextPage();
                    }

                }).delegate(".go", "click",function () { // 点击“确定”去某一页
                    var goToInput = container.find(".go-to");
                    var page = parseInt(goToInput.val());
                    if (isNaN(page) || !page || page < 1 || page > _this._o.totalPage) {
                        goToInput.val(_this._o.index);
                        return false;
                    } else {
                        return _this.goToPage(page);
                    }
                }).delegate(".go-to", "keypress", function (event) { // 页码输入框中敲回车
                    if (event.keyCode == 13) { // 回车键, 代理到go按钮点击事件处理
                        container.find(".go").click();
                    }
                    return true;
                });
            if (_this._o.shortcutSupport) { // 绑定全局的键盘事件
                $(document).delegate(container, "keypress", function (event) {
                    switch (event.keyCode) {
                        case 37: // ← 键  上一页
                            _this.prevPage();
                            break;
                        case 39: // → 键 下一页
                            _this.nextPage();
                            break;
                        case 45: // insert 键  选中"去某页"的输入框
                            container.find(".go-to").select();
                            break;
                    }
                });
            }
        },
        /**
         * 对分页条应用新的配置
         */
        applyOptions : function(options){
            $.extend(this._o, options);
            this._render();
        }
    });

    /**
     * 全局对象,用于保存分页条实例
     * @type {{}}
     */
    $.elfPagination = {};

    /**
     * 注册插件
     * @param options
     * @returns {*}
     */
    $.fn.elfPagination = function (options) {
        if (!this.length) {
            return this;
        }

        var args = Array.prototype.slice.call(arguments, 1); // 其他参数, 作为被调用方法的参数
        return this.each(function () {
            var container = $(this);
            var instance = $.elfPagination[container.data("elf_id")];
            if (typeof options === "string") { // 第一个参数是String类型的. 则进行调用方法
                instance[options].apply(instance, args);
            } else {// 参数是配置对象
                var opts = $.extend({}, $.fn.elfPagination.defaults, options);
                var o = $.metadata ? $.extend({}, opts, container.metadata()) : opts;
                if (!instance) { // 之前没有初始化过,则初始化
                    new ElfPagination(container, o);
                } else { // 之前初始化过,则使用新的配置更新分页条对象
                    instance["applyOptions"].call(instance, options);
                }
            }
        });
    };

    /**
     * 默认配置
     * @type {{}}
     */
    $.fn.elfPagination.defaults = {
        totalPage: 20 // 必选参数， 总页数
        , index: 1 // 当前页
        , numEdge: 1 // 两头分别显示的页码数（前N页和倒数N页）
        , numSiblings: 3 // 当前页两边分别显示的页码数
        , showPrevAndNext: true // 上一页和下一页功能
        , showGoTo: true  // 跳转到某一页
        , showTotalPage: true // 是否显示总页数
        , shortcutSupport: true // 快捷键支持, 当页面中有多个实例时.请将该选项赋值为false
        , paged: function (page) { // 切换到某一页后的回调
        }
    }

})(jQuery);